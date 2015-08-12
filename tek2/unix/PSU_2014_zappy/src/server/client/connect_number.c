/*
** connect_number.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:31:24 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

void		connect_number(t_server *server, t_client *client, char *str)
{
  t_team	*team;
  char		*s;

  (void)str;
  team = find_team_by_name(server->teams, client->team);
  client->player->delay_action = 0;

  asprintf(&s, "%d\n", server->max_clients - team->clients);
  client->messages = append_list(client->messages, strdup(s));
  free(str);
}
