/*
** password_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:37:18 2015 Pierrick Gicquelais
** Last update Wed Apr 15 14:07:50 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"encryption.h"
#include	"password.h"
#include	"swrite.h"

static void	write_password(t_user *user, char *password)
{
  char		*crypt;
  int		xfd;

  if ((xfd = open(".save", O_RDWR | O_APPEND)) != -1)
    {
      crypt = encryption(password);
      swrite(xfd, user->nick);
      swrite(xfd, ":");
      swrite(xfd, crypt);
      swrite(xfd, "\n");
      free(crypt);
    }
  else
    swrite(user->fd, "424 ERR_FILEERROR :Save file missing\r\n");
}

void		pass(t_server *serv, t_user *user, char *cmd)
{
  char		*password;
  char		ret[512];

  (void)serv;
  password = split_string(cmd, ' ', 1);
  if (password != NULL)
    {
      if (!password_exists(user->nick, user->fd))
	{
	  write_password(user, password);
	  sprintf(ret, ":%s PASS :%s\r\n", user->nick, password);
	  swrite(user->fd, ret);
	}
      else
	swrite(user->fd, "464 ERR_PASSWDMISCMATCH :Password already set\r\n");
      free(password);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}
