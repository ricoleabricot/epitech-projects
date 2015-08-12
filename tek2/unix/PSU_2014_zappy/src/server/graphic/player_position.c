/*
** player_position.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:30:36 2015 Pierrick Gicquelais
** Last update Tue Jun 30 15:22:39 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static void     get_position(t_server *server, t_client *client, char *rid)
{
  t_client	*tmp;
  char		*s;

  if ((tmp = get_client_by_socket(server->clients, atoi(rid))) != NULL)
    {
      if (tmp->fd_type == FD_CLIENT)
	{
	  asprintf(&s, "ppo #%d %d %d %d\n", tmp->socket, tmp->player->x, \
		   tmp->player->y, tmp->player->orientation);
	  client->messages = append_list(client->messages, strdup(s));
	  free(s);
	}
      else
	client->messages = append_list(client->messages, strdup("sbp\n"));
    }
  else
    client->messages = append_list(client->messages, strdup("sbp\n"));
}

void		player_position(t_server *server, t_client *client, char *str)
{
  char		*id;
  char		*rid;

  if ((id = split_string(str, ' ', 1)) != NULL)
    {
      if ((rid = split_string(id, '#', 1)) != NULL)
	{
	  get_position(server, client, rid);
	  free(rid);
	}
      else
	client->messages = append_list(client->messages, strdup("sbp\n"));
      free(id);
    }
  else
    client->messages = append_list(client->messages, strdup("sbp\n"));
}
