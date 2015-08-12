/*
** fork.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Wed Jul  1 11:44:54 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

static void	egg_plant(t_server *server, t_client *client, t_client *egg)
{
  char		*s;

  asprintf(&s, "pfk #%d\n", client->socket);
  broadcast(server->clients, s, FD_GRAPHIC);
  free(s);

  asprintf(&s, "enw #%d #%d %d %d\n", egg->socket, client->socket, \
	   egg->player->x, egg->player->y);
  broadcast(server->clients, s, FD_GRAPHIC);
  free(s);
}

void		fork_client(t_server *server, t_client *client, char *str)
{
  int		id;

  (void)str;
  id = (rand() % 1500) + 150;
  client->player->delay_action = (42.f / server->delay) * 1000000;
  client->messages = append_list(client->messages, strdup("ok\n"));

  server->clients = append_client(server->clients, id, FD_FREE, NULL);
  server->clients->team = strdup(client->team);
  server->clients->parent = client->socket;
  create_player_at_pos(server, server->clients, client->player->x, \
		       client->player->y);

  egg_plant(server, client, server->clients);
  server->clients->player->delay_action = (600.f / server->delay) * 1000000;
}
