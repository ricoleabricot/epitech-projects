/*
** read.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 17:03:03 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:13:31 2015 Pierrick Gicquelais
*/

#include	"read_client.h"
#include	"getnextline.h"
#include	"destroy_client.h"
#include	"connection.h"
#include	"get_command.h"
#include	"no_error.h"
#include	"wreturn.h"
#include	"swrite.h"

bool		read_on_input(t_client *cli)
{
  char		*s;
  char		*cmd;

  if ((s = getnextline(0)) != NULL)
    {
      connection(cli, s);
      if (cli->is_connected)
	{
	  cmd = get_command(s);
	  if (no_error(cmd))
	    {
	      swrite(cli->fd, cmd);
	      swrite(cli->fd, "\n");
	    }
	  free(cmd);
	}
      free(s);
    }
  else
    return (true);
  return (false);
}

bool		read_on_socket(t_client *cli)
{
  char		buf[512];
  int		r;

  r = read(cli->fd, buf, 512);
  if (r > 0)
    {
      buf[r] = '\0';
      rreturn(cli);
      freturn(buf);
      wreturn(cli, buf);
    }
  else
    return (true);
  return (false);
}
