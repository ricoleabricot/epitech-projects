/*
** map_size.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:29:15 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:46:48 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		map_size(t_server *server, t_client *client, char *str)
{
  char		*s;

  (void)str;
  asprintf(&s, "msz %d %d\n", server->width, server->height);
  client->messages = append_list(client->messages, strdup(s));
  free(s);
}
