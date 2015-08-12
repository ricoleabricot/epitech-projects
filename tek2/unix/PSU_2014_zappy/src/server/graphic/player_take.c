/*
** player_take.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 18:02:44 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:16:33 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

void		player_take(t_server *server, t_client *client, int resources)
{
  t_case	*pos;
  char		*str;
  int		*res;

  asprintf(&str, "pgt #%d %d\n", client->socket, resources);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);

  res = client->player->resources;
  asprintf(&str, "pin #%d %d %d %d %d %d %d %d %d %d\n", client->socket, \
	   client->player->x, client->player->y, res[FOOD], res[LINEMATE],
	   res[DERAUMERE], res[SIBUR], res[MENDIANE], res[PHIRAS],
	   res[THYSTAME]);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);

  pos = find_case_by_index(server->map, client->player->x, client->player->y);
  res = pos->resources;
  asprintf(&str, "bct %d %d %d %d %d %d %d %d %d\n", client->player->x, \
	   client->player->y, res[FOOD], res[LINEMATE], res[DERAUMERE], \
	   res[SIBUR], res[MENDIANE], res[PHIRAS], res[THYSTAME]);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);
}
