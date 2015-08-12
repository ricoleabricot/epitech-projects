/*
** run.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:48:18 2015 Pierrick Gicquelais
** Last update Fri Jul  3 10:31:26 2015 Pierrick Gicquelais
*/

#include	"server/run.h"

bool		g_stop;

static void	sig_handler(int sig)
{
  (void)sig;
  g_stop = true;
}

static int	initialize_run(t_client *clients, fd_set *fd_read, \
			       fd_set *fd_write)
{
  int		fd_max;

  fd_max = 0;
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);

  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type != FD_FREE)
	{
	  if (clients->socket > fd_max)
	    fd_max = clients->socket;
	  FD_SET(clients->socket, fd_read);
	  FD_SET(clients->socket, fd_write);
	}

      clients = clients->next;
    }

  return (fd_max);
}

static void	launch(t_server *server, t_client *clients, fd_set fd_read, \
		       fd_set fd_write)
{
  t_client	*tmp;

  clients = first_client(server->clients);
  while (clients)
    {
      tmp = clients->next;

      if (FD_ISSET(clients->socket, &fd_read))
	if (clients->fct_read != NULL)
	  server->clients = clients->fct_read(server, clients->socket);

      clients = tmp;
    }

  clients = first_client(server->clients);
  while (clients)
    {
      tmp = clients->next;

      if (FD_ISSET(clients->socket, &fd_write))
	if (clients->fct_write != NULL)
	  server->clients = clients->fct_write(server, clients, server->verbose);

      clients = tmp;
    }
}

void			run(t_server *server)
{
  int			fd;
  fd_set		fd_read;
  fd_set		fd_write;
  struct timeval	old_time;
  struct timeval	new_time;
  struct timeval	tv;

  if (server->verbose)
    aff_server(server);
  gettimeofday(&new_time, NULL);
  g_stop = false;
  while (!g_stop && !server->end)
    {
      signal(SIGINT, sig_handler);
      signal(SIGPIPE, SIG_IGN);
      update(&old_time, &new_time, server, server->clients);

      tv.tv_sec = 0;
      tv.tv_usec = (7.f / server->delay) * 100000;
      fd = initialize_run(server->clients, &fd_read, &fd_write);
      if (select(fd + 1, &fd_read, &fd_write, NULL, &tv) == -1)
        server->end = true;
      else
	launch(server, server->clients, fd_read, fd_write);
    }
}
