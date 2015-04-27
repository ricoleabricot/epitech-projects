/*
** run.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 13:17:04 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:53:40 2015 Pierrick Gicquelais
*/

#include	"run_client.h"
#include	"read_client.h"
#include	"destroy_client.h"
#include	"file_client.h"
#include	"swrite.h"

t_client	*g_cli;

static void	sig_handler(int sig)
{
  (void)sig;
  destroy(g_cli);
  exit(EXIT_SUCCESS);
}

static void	initialize_run(t_client *cli)
{
  signal(SIGINT, sig_handler);
  signal(SIGPIPE, sig_handler);
  g_cli = cli;

  FD_ZERO(&cli->fd_read);
  FD_SET(0, &cli->fd_read);
  FD_SET(cli->fd, &cli->fd_read);
}

static void	write_prompt(t_client *cli)
{
  if (!cli->is_connected)
    swrite(1, "myIRC$> ");
  else
    {
      if (cli->nick != NULL)
	swrite(1, cli->nick);
      swrite(1, "@");
      if (cli->ch != NULL)
	swrite(1, cli->ch);
      else
	swrite(1, "KafeIRC");
      swrite(1, "$> ");
    }
}

void		run(t_client *cli)
{
  bool		stop;

  stop = false;
  while (!stop)
    {
      write_prompt(cli);
      initialize_run(cli);

      if (select(cli->fd + 1, &cli->fd_read, NULL, NULL, NULL) == -1)
	stop = true;
      else
	{
	  if (FD_ISSET(0, &cli->fd_read))
	    stop = read_on_input(cli);
	  if (cli->is_connected && FD_ISSET(cli->fd, &cli->fd_read))
	    stop = read_on_socket(cli);
	  if (cli->is_connected && FD_ISSET(cli->sf, &cli->fd_read))
	    receive_file(cli);
	}
    }
}
