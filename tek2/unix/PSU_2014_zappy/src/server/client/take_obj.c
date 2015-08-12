/*
** take_obj.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:37:51 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

static	char	(*g_str[8]) =
{
  "nourriture",
  "linemate",
  "deraumere",
  "sibur",
  "mendiane",
  "phiras",
  "thystame",
  NULL
};

static	int	(g_res[8]) =
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  0
};

static t_client	*get_obj(t_server *server, t_client *client, int i)
{
  t_case	*pos;

  pos = find_case_by_index(server->map, client->player->x, client->player->y);
  if (pos->resources[g_res[i]] > 0)
    {
      client->player->resources[g_res[i]]++;
      pos->resources[g_res[i]]--;
      client->messages = append_list(client->messages, strdup("ok\n"));
      player_take(server, client, g_res[i]);
    }
  else
    client->messages = append_list(client->messages, strdup("ko\n"));

  return (client);
}

void		take_obj(t_server *server, t_client *client, char *str)
{
  char		*resources;
  int		i;

  (void)str;
  resources = split_string(str, ' ', 1);
  if (resources)
    {
      i = 0;
      while (g_str[i] && strcmp(g_str[i], resources) != 0)
	i++;

      if (g_str[i] != NULL)
	client = get_obj(server, client, i);
      else
	client->messages = append_list(client->messages, strdup("ko\n"));
      free(resources);
    }
  else
    client->messages = append_list(client->messages, strdup("ko\n"));

  client->player->delay_action = (7.f / server->delay) * 1000000;
}
