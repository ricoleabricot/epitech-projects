/*
** wreturn.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Mar 21 12:53:37 2015 Pierrick Gicquelais
** Last update Wed Mar 25 15:24:45 2015 Pierrick Gicquelais
*/

#include	"wreturn.h"
#include	"set_user.h"
#include	"destroy_client.h"

static void	check_return(t_client *cli, char *ret, char *cmd)
{
  if (strcmp(ret, "331 Username okay, need password\r\n") == 0)
    set_user(cli, cmd);
  else if (strcmp(ret, "230 User logged in, proceed\r\n") == 0)
    {
      if (cli->username == NULL)
	set_user(cli, cmd);
      cli->login = true;
    }
  else if (strcmp(ret, "220 Disconnected\r\n") == 0)
    {
      cli->username = NULL;
      cli->login = false;
    }
  else if (strcmp(ret, "221 Bye.\r\n") == 0)
    {
      write(1, ret, strlen(ret));
      destroy(cli);
    }
  write(1, ret, strlen(ret));
}

void		wreturn(t_client *cli, char *ret, char *cmd)
{
  memset(ret, 0, 4096);
  read(cli->fd, ret, 4096);
  check_return(cli, ret, cmd);
}
