/*
** run.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:22:20 2015 Pierrick Gicquelais
** Last update Wed Mar 25 15:09:27 2015 Pierrick Gicquelais
*/

#include	"run_client.h"
#include	"getnextline.h"
#include	"trim.h"
#include	"do_actions_client.h"
#include	"destroy_client.h"
#include	"xconnect.h"
#include	"xopen.h"
#include	"wreturn.h"

#include	"swrite.h"

t_client	*g_client;

static void	int_handler(int sig)
{
  (void)sig;
  write(1, "\nBye.\n", strlen("\nBye.\n"));
  destroy(g_client);
  exit(EXIT_SUCCESS);
}

static char	*get_line(t_client *cli, int fd)
{
  if (cli->username != NULL && cli->login == true)
    {
      write(1, cli->username, strlen(cli->username));
      write(1, "$> ", strlen("$> "));
    }
  else
    write(1, "myFTP$> ", strlen("myFTP$> "));
  return (getnextline(fd));
}

void		run(t_client *cli)
{
  char		*s;
  char		*trimstr;
  char		ret[4096];

  g_client = cli;
  signal(SIGINT, int_handler);
  while ((s = get_line(cli, 0)) != NULL)
    {
      trimstr = trim(s);
      if (trimstr[0])
	do_actions(cli, trimstr);
      else
	write(cli->fd, "\n", 1);

      wreturn(cli, ret, trimstr);
      free(trimstr);
      free(s);
    }
}
