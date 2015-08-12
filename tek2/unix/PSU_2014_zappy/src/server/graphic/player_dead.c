/*
** player_dead.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 18:07:34 2015 Pierrick Gicquelais
** Last update Sat Jun 27 18:08:18 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		player_dead(t_server *server, t_client *client)
{
  char		*str;

  asprintf(&str, "pdi #%d\n", client->socket);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);
}
