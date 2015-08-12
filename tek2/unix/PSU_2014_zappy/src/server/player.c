/*
** player.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 17:22:42 2015 Pierrick Gicquelais
** Last update Tue Jun 30 14:30:38 2015 Pierrick Gicquelais
*/

#include	"server/server.h"
#include	"server/player.h"

void		create_player(t_server *server, t_client *client)
{
  t_player	*player;

  player = xmalloc(sizeof(t_player));
  init_player(player, client->socket, client->team);
  add_player(server, player, server->width, server->height);
  player->client = client;
  client->player = player;
}

void		add_player(t_server *server, t_player *player, int w, int h)
{
  int		x;
  int		y;

  x = rand() % w;
  y = rand() % h;
  if (server)
    add_player_to_pos(server, player, x, y);
}

void		create_player_at_pos(t_server *server, t_client *client, \
				     int x, int y)
{
  t_player	*player;

  player = xmalloc(sizeof(t_player));
  init_player(player, client->socket, client->team);
  add_player_to_pos(server, player, x, y);
  player->client = client;
  client->player = player;
}

void		add_player_to_pos(t_server *server, t_player *player, \
				  int x, int y)
{
  t_case	*cas;

  player->x = x;
  player->y = y;
  if (server)
    {
      correct_pos(server, &x, &y);
      cas = find_case_by_index(server->map, x, y);
      if (cas)
	cas->player = append_list(cas->player, player);
    }
}

void		init_player(t_player *player, int id, char *team)
{
  player->id = id;
  player->team = strdup(team);
  player->level = 1;
  player->delay_action = 0;
  player->delay_food = 0;
  player->x = 0;
  player->y = 0;
  player->orientation = rand() % 4 + 1;

  player->resources[FOOD] = 10;
  player->resources[LINEMATE] = 0;
  player->resources[DERAUMERE] = 0;
  player->resources[SIBUR] = 0;
  player->resources[MENDIANE] = 0;
  player->resources[PHIRAS] = 0;
  player->resources[THYSTAME] = 0;

  player->actions = NULL;
  player->spell = false;
}
