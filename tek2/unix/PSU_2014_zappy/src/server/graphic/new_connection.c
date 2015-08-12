/*
** new_connection.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 12:07:47 2015 Pierrick Gicquelais
** Last update Fri Jun 26 12:09:25 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		new_connection(t_server *server, t_client *client)
{
  char		*str;

  asprintf(&str, "pnw #%d %d %d %d %d %s\n", client->socket, \
	   client->player->x, client->player->y, \
	   client->player->orientation, client->player->level, \
	   client->team);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);
}
