/*
** spell.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Tue Jun 30 17:08:14 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

static char	*add_return(char *s)
{
  char		*old_s;

  old_s = s;
  asprintf(&s, "%s\n", s);
  if (old_s)
    free(old_s);

  return (s);
}

static char	*fill(t_client *client, t_case *pos, char *s)
{
  t_list	*tmp;
  t_player	*player;
  char		*old_s;

  tmp = pos->player;
  while (tmp)
    {
      if (tmp->data)
	{
	  player = ((t_player *)tmp->data);
	  if (player->client->socket != client->socket && \
	      player->level == client->player->level)
	    {
	      old_s = s;
	      asprintf(&s, "%s %d", s, player->client->socket);
	      if (old_s)
		free(old_s);
	    }
	}
      tmp = tmp->next;
    }
  return (add_return(s));
}

void		spell(t_server *server, t_client *client, char *str)
{
  t_case	*pos;
  char		*s;

  (void)str;
  pos = find_case_by_index(server->map, client->player->x, client->player->y);
  if (check_stones(pos, client->player->level) && \
      check_players(pos, client->player->level))
    {
      client->player->delay_action = (300.f / server->delay) * 1000000;

      asprintf(&s, "pic %d %d %d #%d", client->player->x, client->player->y, \
	       client->player->level, client->socket);
      s = fill(client, pos, s);

      client->player->spell = true;
      client->messages = append_list(client->messages, \
				     strdup("elevation en cours\n"));
      broadcast(server->clients, s, FD_GRAPHIC);
      free(s);
    }
  else
    client->messages = append_list(client->messages, strdup("ko\n"));
}
