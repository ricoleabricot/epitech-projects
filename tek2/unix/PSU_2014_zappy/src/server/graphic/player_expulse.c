/*
** player_expulse.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 19:46:44 2015 Pierrick Gicquelais
** Last update Sat Jun 27 19:55:31 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static void	new_positions(t_server *server, t_client *clients)
{
  char		*str;

  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type == FD_CLIENT)
	{
	  asprintf(&str, "ppo #%d %d %d %d\n", clients->socket, \
		   clients->player->x, clients->player->y, \
		   clients->player->orientation);
	  broadcast(server->clients, str, FD_GRAPHIC);
	  free(str);
	}
      clients = clients->next;
    }
}

void		player_expulse(t_server *server, t_client *client)
{
  char		*str;

  asprintf(&str, "pex #%d\n", client->socket);
  broadcast(server->clients, str, FD_GRAPHIC);
  free(str);

  new_positions(server, server->clients);
}
