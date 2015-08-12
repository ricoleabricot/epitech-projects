/*
** update.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 25 11:00:36 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:13:06 2015 Pierrick Gicquelais
*/

#include	"server/update.h"

static t_client	*starve(t_server *server, t_client *tmp)
{
  t_team	*team;

  --(tmp->player->resources[FOOD]);
  if (tmp->player->resources[FOOD] == -1)
    {
      team = find_team_by_name(server->teams, tmp->team);
      team->clients--;
      swrite(tmp->socket, "mort\n");
      player_dead(server, tmp);
      server->clients = pop_client(server->clients, tmp->socket);
      tmp = server->clients;
    }
  else
    tmp->player->delay_food += (126.f / server->delay) * 1000000;

  return (tmp);
}

static t_client	*egg(t_server *server, t_client *tmp, int elapsed_time)
{
  char		*s;

  if (tmp && tmp->player)
    {
      tmp->player->delay_action -= elapsed_time;
      if (tmp->player->delay_action <= 0)
	{
	  asprintf(&s, "edi #%d\n", tmp->socket);
	  broadcast(server->clients, s, FD_GRAPHIC);
	  free(s);

	  server->clients = pop_client(server->clients, tmp->socket);
	}
    }
  return (server->clients);
}

static void     incantation(t_server *server, t_client *tmp)
{
  t_case	*pos;
  bool		spell;
  char		*s;

  tmp->player->spell = false;
  pos = find_case_by_index(server->map, tmp->player->x, tmp->player->y);
  if ((spell = (check_stones(pos, tmp->player->level) && \
		check_players(pos, tmp->player->level))) == true)
    {
      clear_case(pos);
      level_up(pos);

      if (tmp->player->level > 7)
	end_game(server, server->clients, tmp);
    }

  if (tmp->player->level < 7)
    {
      asprintf(&s, "niveau actuel : %d\n", tmp->player->level);
      tmp->messages = append_list(tmp->messages, strdup(s));
      free(s);
      asprintf(&s, "pie %d %d %d\n", tmp->player->x, tmp->player->y, spell);
      broadcast(server->clients, s, FD_GRAPHIC);
      free(s);
    }
}

static void	action(t_server *server, t_client *tmp)
{
  if (tmp->player)
    {
      if (tmp->player->delay_action <= 0 && tmp->player->spell == true)
	incantation(server, tmp);
      if (tmp->player->actions != NULL && tmp->player->delay_action <= 0)
	{
	  commands_client(server, tmp, tmp->player->actions->data);
	  if (tmp->player->actions->data)
	    free(tmp->player->actions->data);
	  tmp->player->actions = delete_list(tmp->player->actions);
	}
    }
}

void		update(struct timeval *old_time, struct timeval *new_time, \
		       t_server *server, t_client *clients)
{
  t_client	*tmp;
  int		elapsed_time;

  (*old_time) = (*new_time);
  gettimeofday(new_time, NULL);
  elapsed_time = (new_time->tv_sec * 1000000ull + new_time->tv_usec) - \
    (old_time->tv_sec * 1000000ull + old_time->tv_usec);
  tmp = first_client(clients);
  while (tmp)
    {
      if (tmp->fd_type == FD_FREE)
	tmp = egg(server, tmp, elapsed_time);

      if (tmp->player && tmp->fd_type == FD_CLIENT)
	{
	  if (tmp->player->delay_action > 0)
	    tmp->player->delay_action -= elapsed_time;
	  tmp->player->delay_food -= elapsed_time;
	  if (tmp->player->delay_food <= 0)
	    tmp = starve(server, tmp);
	  action(server, tmp);
	}
      tmp = tmp->next;
    }
}
