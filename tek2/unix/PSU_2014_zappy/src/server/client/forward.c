/*
** forward.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:29:08 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

void		forward(t_server *server, t_client *client, char *str)
{
  char		*s;
  int		x;
  int		y;

  (void)str;
  get_new_pos(server, client->player, &x, &y);
  move_player_to_pos(server->map, client->player, x, y);
  client->player->delay_action = (7.f / server->delay) * 1000000;
  client->messages = append_list(client->messages, strdup("ok\n"));

  asprintf(&s, "ppo #%d %d %d %d\n", client->socket, client->player->x, \
	   client->player->y, client->player->orientation);
  broadcast(server->clients, s, FD_GRAPHIC);
  free(s);
}
