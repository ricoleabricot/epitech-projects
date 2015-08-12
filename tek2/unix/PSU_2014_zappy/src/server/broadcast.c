/*
** broadcast.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 18:40:28 2015 Pierrick Gicquelais
** Last update Thu Jul  2 12:41:24 2015 Christian Boisson
*/

# define	_GNU_SOURCE

#include	<math.h>
#include	"server/commands_client.h"
#include	"server/server.h"
#include	"server/broadcast.h"
#include	"server/abs.h"

int		get_k(t_server *server, t_player *src, t_player *tgt)
{
  int		xb;
  int		yb;
  int		k;

  xb = server->width;
  yb = server->height;
  get_virtual_pos(src, tgt, &xb, &yb);
  k = get_tmp_k(src->x, src->y, xb, yb);
  return (alter_k(k, tgt->orientation));
}

void		broadcast(t_client *clients, char *s, char type)
{
  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type == type)
	clients->messages = append_list(clients->messages, strdup(s));
      clients = clients->next;
    }
}

void		broadcast_players(t_server *server, t_client *clients, \
				  t_client *src, char *str)
{
  char		*msg;

  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type == FD_CLIENT && clients->socket != src->socket)
	{
	  asprintf(&msg, "message %d, %s\n", \
		   get_k(server, src->player, clients->player), str);
	  clients->messages = append_list(clients->messages, strdup(msg));
	  free(msg);
	}
      clients = clients->next;
    }
}
