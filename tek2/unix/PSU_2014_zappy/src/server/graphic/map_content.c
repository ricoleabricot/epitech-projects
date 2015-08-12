/*
** map_content.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:28:03 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:46:26 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static void	print_resources(t_client *client, t_case *pos, int x, int y)
{
  char		*s;
  int		*res;

  res = pos->resources;
  asprintf(&s, "bct %d %d %d %d %d %d %d %d %d\n", x, y, res[FOOD], \
	   res[LINEMATE], res[DERAUMERE], res[SIBUR], \
	   res[MENDIANE], res[PHIRAS], res[THYSTAME]);
  client->messages = append_list(client->messages, strdup(s));
  free(s);
}

void	        map_content(t_server *server, t_client *client, char *str)
{
  t_list	*tmp;
  t_list	*y_tmp;
  int		x;
  int		y;

  (void)str;
  if (server->map)
    {
      tmp = server->map->begin;
      x = 0;
      while (tmp)
	{
	  y_tmp = tmp->data;
	  y = 0;
	  while (y_tmp)
	    {
	      if (y_tmp->data)
		print_resources(client, y_tmp->data, x, y);
	      y_tmp = y_tmp->next;
	      y++;
	    }
	  tmp = tmp->next;
	  x++;
	}
    }
}
