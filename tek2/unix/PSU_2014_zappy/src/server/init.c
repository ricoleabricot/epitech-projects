/*
** init.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:48:02 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:03:01 2015 Pierrick Gicquelais
*/

#include	"server/init.h"

static t_case	*initialize_case(void)
{
  t_case	*tmp;
  int		i;

  tmp = xmalloc(sizeof(t_case));
  i = 0;
  while (i < RESOURCES)
    {
      tmp->resources[i] = 0;
      ++i;
    }
  tmp->player = NULL;
  return (tmp);
}

static void	initialize_map(t_server *server)
{
  t_list	*map;
  t_list	*y_map;
  t_case	*tmp;
  int		i;
  int		j;

  map = NULL;
  i = 0;
  while (i < server->width)
    {
      y_map = NULL;
      j = 0;
      while (j < server->height)
	{
	  tmp = initialize_case();
	  y_map = append_list(y_map, tmp);
	  ++j;
	}
      map = append_list(map, y_map);
      ++i;
    }
  server->map = map;
}

static void	initialize_sockets(t_server *server)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  int			socket;

  pe = xgetprotobyname("TCP");
  socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->port);
  sin.sin_addr.s_addr = INADDR_ANY;

  xbind(socket, (const struct sockaddr *)&sin, sizeof(sin));
  xlisten(socket, 1);

  server->clients = append_client(server->clients, socket, FD_SERVER, \
				  server_read);
}

void		init(t_server *server, int argc, char **argv)
{
  server->port = 0;
  server->width = 0;
  server->height = 0;
  server->teams = NULL;
  server->max_clients = 0;
  server->delay = 0;
  server->clients = NULL;
  server->verbose = false;

  get_options(server, argc, argv);
  check_options(server);

  initialize_sockets(server);
  initialize_map(server);

  server->end = false;
}
