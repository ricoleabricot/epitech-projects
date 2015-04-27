/*
** run.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:26:31 2015 Pierrick Gicquelais
** Last update Sun Apr 12 16:55:22 2015 Pierrick Gicquelais
*/

#include	"run_server.h"
#include	"destroy_server.h"

t_server	*g_serv;

static void	sig_handler(int sig)
{
  (void)sig;
  destroy(g_serv);
  exit(EXIT_SUCCESS);
}

static int      initialize_run(t_server *serv, fd_set *fd_read)
{
  int		fd_max;
  int		i;

  g_serv = serv;
  signal(SIGINT, sig_handler);
  signal(SIGPIPE, sig_handler);
  FD_ZERO(fd_read);

  fd_max = 0;
  i = 0;
  while (i < FD_MAX)
    {
      if (serv->fd_type[i] != FD_FREE)
	{
	  fd_max = i;
	  if (fd_max >= FD_MAX - 1)
	    {
	      destroy(serv);
	      exit(EXIT_FAILURE);
	    }
	  FD_SET(fd_max, fd_read);
	}
      i++;
    }
  return (fd_max);
}

void		run(t_server *serv)
{
  bool	        stop;
  int		i;
  int		fd_max;
  fd_set	fd_read;

  stop = false;
  while (!stop)
    {
      fd_max = initialize_run(serv, &fd_read);

      if (select(fd_max + 1, &fd_read, NULL, NULL, &serv->tv) == -1)
	stop = true;
      else
	{
	  i = 0;
	  while (i < FD_MAX)
	    {
	      if (FD_ISSET(i, &fd_read))
		if (serv->fct_read[i])
		  serv->fct_read[i](serv, i);
	      i++;
	    }
	}
    }
}
