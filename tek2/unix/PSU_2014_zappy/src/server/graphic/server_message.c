/*
** server_message.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jul  2 13:45:23 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:47:15 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		server_message(t_server *server, char *str)
{
  char		*s;

  asprintf(&s, "smg %s\n", str);
  broadcast(server->clients, s, FD_GRAPHIC);
  free(s);
}
