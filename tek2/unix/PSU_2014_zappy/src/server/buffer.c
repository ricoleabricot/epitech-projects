/*
** buffer.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jul  2 12:32:27 2015 Pierrick Gicquelais
** Last update Thu Jul  2 12:39:44 2015 Pierrick Gicquelais
*/

#include	"server/buffer.h"

t_client	*buffering(t_server *server, char *str, int s)
{
  t_client	*client;
  char		*cmd;
  int		i;

  i = 1;
  client = get_client_by_socket(server->clients, s);
  while ((cmd = split_string(str, '\n', i)) != NULL)
    {
      printf("%s\n", cmd);
      client->player->actions = append_list(client->player->actions, \
					    strdup(cmd));
      free(cmd);
      i++;
    }

  return (client);
}
