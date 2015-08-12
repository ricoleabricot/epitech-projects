/*
** set_delay.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:30:36 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:49:11 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void	        set_delay(t_server *server, t_client *client, char *str)
{
  char		*value;
  char		*s;

  if ((value = split_string(str, ' ', 1)) != NULL)
    {
      server->delay = atoi(value);
      asprintf(&s, "sgt %s\n", value);
      client->messages = append_list(client->messages, strdup(s));
      free(s);
      free(value);
    }
  else
    client->messages = append_list(client->messages, strdup("sbp\n"));
}
