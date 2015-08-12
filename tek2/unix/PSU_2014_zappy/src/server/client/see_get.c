/*
** see_data.c for zappy in /home/boisso_c/rendu/PSU_2014_zappy/src/server/client
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 29 16:21:23 2015 Christian Boisson
** Last update Sun Jul  5 12:24:57 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"
#include	"server/server.h"
#include	"server/see.h"

static void	get_delta(t_player *player, int *dx, int *dy)
{
  if (player)
    {
      (*dx) = 0;
      (*dy) = 0;
      if (player->orientation == NORTH)
	--(*dy);
      else if (player->orientation == WEST)
	--(*dx);
      else if (player->orientation == EAST)
	++(*dx);
      else if (player->orientation == SOUTH)
	++(*dy);
    }
}

static void	begin_line(int *x, int *y, t_player *player, int lvl)
{
  int		dx;
  int		dy;

  get_delta(player, &dx, &dy);
  (*x) = player->x + (dx * lvl) + (dy * lvl);
  (*y) = player->y - (dx * lvl) + (dy * lvl);
}

void		get_resources(t_case *cas, char **str)
{
  char		*old_string;
  static char	*str_res[] = RESTABLE;
  int		i;
  int		j;

  i = 0;
  while (i < RESOURCES)
    {
      j = 0;
      while (cas->resources[i] > j)
	{
	  old_string = (*str);
	  asprintf(str, "%s%s", (*str), str_res[i]);
	  if (old_string)
	    {
	      free(old_string);
	      old_string = NULL;
	    }
	  ++j;
	}
      ++i;
    }
}

char		*get_case(t_client *client, t_case *cas, int lvl)
{
  char		*str;
  char		*old_s;
  t_list	*tmp;

  str = xmalloc(1);
  str[0] = '\0';
  if (cas)
    {
      tmp = cas->player;
      if (tmp)
	{
	  if (lvl > 0 || (tmp->data != client->player || \
			  ((tmp = tmp->next) != NULL)))
	    while (tmp)
	      {
		old_s = str;
		asprintf(&str, "%s %s", str, "joueur");
		if (old_s)
		  free(old_s);
		tmp = tmp->next;
	      }
	}
      get_resources(cas, &str);
    }
  return (str);
}

char		*get_line(t_server *s, t_client *client, int lvl, int cas)
{
  int		x;
  int		y;
  int		dx;
  int		dy;
  char		*str;
  char		*tmp;

  begin_line(&x, &y, client->player, lvl);
  get_delta(client->player, &dx, &dy);
  str = xmalloc(1);
  str[0] = '\0';
  while (cas > 0)
    {
      correct_pos(s, &x, &y);
      if ((tmp = get_case(client, find_case_by_index(s->map, x, y), \
			  lvl)) != NULL)
	str = print_line(str, tmp, lvl, cas);
      aply_dx(client, &x, dy);
      aply_dy(client, &y, dx);
      --cas;
    }
  return (str);
}
