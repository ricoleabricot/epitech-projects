/*
** egg.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 29 18:17:24 2015 Pierrick Gicquelais
** Last update Mon Jun 29 18:53:52 2015 Pierrick Gicquelais
*/

#include	"server/egg.h"

t_client	*check_egg(t_server *server, t_client *client)
{
  t_client	*egg;
  char		*s;

  if ((egg = get_client_egg_by_team(server->clients, client->team)) != NULL)
    {
      asprintf(&s, "eht #%d\n", egg->socket);
      broadcast(server->clients, s, FD_GRAPHIC);
      free(s);

      asprintf(&s, "ebo #%d\n", egg->socket);
      broadcast(server->clients, s, FD_GRAPHIC);
      free(s);

      client->player = egg->player;
      server->clients = pop_client(server->clients, egg->socket);
    }
  else
    create_player(server, client);

  return (server->clients);
}
