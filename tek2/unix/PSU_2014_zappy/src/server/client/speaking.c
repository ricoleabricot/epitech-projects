/*
** broadcast.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:54:48 2015 Christian Boisson
*/

#include	"server/commands_client.h"

void	        speaking(t_server *server, t_client *client, char *str)
{
  char		*s;

  s = split_string(str, ' ', 1);
  if (s)
    {
      broadcast_players(server, server->clients, client, s);
      client->messages = append_list(client->messages, strdup("ok\n"));

      player_speaking(server, client, s);

      free(s);
    }
  else
    client->messages = append_list(client->messages, strdup("ko\n"));

  client->player->delay_action = (7.f / server->delay) * 1000000;
}
