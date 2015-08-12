/*
** player_speaking.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 17:54:58 2015 Pierrick Gicquelais
** Last update Sat Jun 27 17:56:30 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		player_speaking(t_server *server, t_client *client, char *msg)
{
  char		*str;

  asprintf(&str, "pbc #%d %s\n", client->socket, msg);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);
}
