/*
** nick_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:38:50 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:29:46 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"broadcast.h"
#include	"password.h"
#include	"encryption.h"
#include	"swrite.h"

static void	change_nick(t_server *serv, t_user *user, char *nick)
{
  char		ret[512];

  sprintf(ret, "NICK %s\r\n", nick);
  swrite(user->fd, ret);
  sprintf(ret, ":%s NICK %s\r\n", user->nick, nick);
  broadcast(serv, user, ret);

  user->nick = strdup(nick);
}

static void	connection(t_server *serv, t_user *user, char *nick, char *cmd)
{
  char		*password;
  char		*encrypt;

  if (!password_exists(nick, user->fd))
    change_nick(serv, user, nick);
  else
    {
      password = split_string(cmd, ' ', 2);
      if (password != NULL)
	{
	  encrypt = encryption(password);

	  if (password_correct(nick, encrypt, user->fd))
	    change_nick(serv, user, nick);
	  else
	    swrite(user->fd, "464 ERR_PASSWDMISMATCH :Wrong password\r\n");
	  free(encrypt);
	}
      else
	swrite(user->fd, \
	       "464 ERR_PASSWDMISMATCH :You need to enter a password\r\n");
      free(password);
    }
}

void		nick(t_server *serv, t_user *user, char *cmd)
{
  char		*nick;

  nick = split_string(cmd, ' ', 1);
  if (nick != NULL)
    {
      if (strlen(nick) < 64 && strstr(nick, "_") == NULL)
	{
	  if (!user_exists(serv->users, nick))
	    connection(serv, user, nick, cmd);
	  else
	    swrite(user->fd, \
		   "433 ERR_NICKNAMEINUSE :Nickname is already in use\r\n");
	}
      else
	swrite(user->fd, "432 ERR_ERRONEUSENICKNAME :Error nickname\r\n");
      free(nick);
    }
  else
    swrite(user->fd, "431 ERR_NONICKNAMEGIVEN :No nickname given\r\n");
}
