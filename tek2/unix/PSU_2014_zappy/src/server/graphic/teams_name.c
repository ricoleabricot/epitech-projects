/*
** teams_name.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:28:03 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:49:35 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void	        teams_name(t_server *server, t_client *client, char *str)
{
  t_team	*tmp;
  char		*s;

  (void)str;
  tmp = first_team(server->teams);
  while (tmp)
    {
      asprintf(&s, "tna %s\n", tmp->name);
      client->messages = append_list(client->messages, strdup(s));
      free(s);
      tmp = tmp->next;
    }
}
