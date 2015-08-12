/*
** inventory.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:33:47 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

void		inventory(t_server *server, t_client *client, char *str)
{
  char		*s1;
  char		*s2;
  int		*resources;

  (void)str;
  resources = client->player->resources;

  asprintf(&s1, "{nourriture %d,linemate %d,deraumere %d,sibur %d,mendiane %d",
	   resources[FOOD], resources[LINEMATE], resources[DERAUMERE],
	   resources[SIBUR], resources[MENDIANE]);
  asprintf(&s2, "%s,phiras %d, thystame %d}\n", s1, resources[PHIRAS],
	   resources[THYSTAME]);

  free(s1);
  client->player->delay_action = (7.f / server->delay) * 1000000;
  client->messages = append_list(client->messages, strdup(s2));
  free(s2);
}
