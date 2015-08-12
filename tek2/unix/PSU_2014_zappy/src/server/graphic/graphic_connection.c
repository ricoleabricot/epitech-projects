/*
** graphic_connection.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 16:57:39 2015 Pierrick Gicquelais
** Last update Wed Jul  1 11:45:27 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static void	show_eggs(t_client *client, t_client *tmp)
{
  char		*str;

  tmp = first_client(tmp);
  while (tmp)
    {
      if (tmp->fd_type == FD_FREE)
	{
	  asprintf(&str, "enw #%d #%d %d %d\n", tmp->socket, \
		   tmp->parent, tmp->player->x, tmp->player->y);
	  client->messages = append_list(client->messages, strdup(str));
	  free(str);
	}
      tmp = tmp->next;
    }
}

static void	show_players(t_client *client, t_client *tmp)
{
  char		*str;

  tmp = first_client(tmp);
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT)
	{
	  asprintf(&str, "pnw #%d %d %d %d %d %s\n", tmp->socket, \
		   tmp->player->x, tmp->player->y, \
		   tmp->player->orientation, tmp->player->level, \
		   tmp->team);
	  client->messages = append_list(client->messages, strdup(str));
	  free(str);
	}
      tmp = tmp->next;
    }
}

void		graphic_connection(t_server *server, int s)
{
  t_client	*client;

  client = get_client_by_socket(server->clients, s);
  map_size(server, client, NULL);
  get_delay(server, client, NULL);
  map_content(server, client, NULL);
  show_players(client, server->clients);
  show_eggs(client, server->clients);

  if (server->verbose == true)
    verbose_connection(client);
}
