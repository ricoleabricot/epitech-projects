/*
** misc_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:30:08 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:56:36 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"broadcast.h"
#include	"swrite.h"

void		server(t_server *serv, t_user *user, char *cmd)
{
  (void)serv;
  (void)cmd;

  swrite(user->fd, ":Already connected to server\r\n");
}

void		topic(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;
  char		*topic;
  char		ret[512];

  if (user->ch != NULL)
    {
      ch = get_channel_by_name(serv->channels, user->ch);
      topic = split_string(cmd, ' ', 1);
      if (topic != NULL && strlen(topic) < 128)
	{
	  ch->topic = strdup(topic);
	  free(topic);
	}

      if (ch->topic != NULL)
	sprintf(ret, "332 RPL_TOPIC :%s\r\n", ch->topic);
      else
	sprintf(ret, "331 RPL_NOTOPIC :No topic is set\r\n");
      swrite(user->fd, ret);
    }
  else
    swrite(user->fd, "461 ERR_USERNOTINCHANNEL :You're not in a channel\r\n");
}

void		quit(t_server *serv, t_user *user, char *cmd)
{
  char		ret[512];
  int		fd;

  (void)cmd;
  if (user->ch != NULL)
    {
      sprintf(ret, ":%s QUIT %s\r\n", user->nick, user->ch);
      broadcast(serv, user, ret);
    }

  fd = user->fd;
  serv->users = pop_user(serv->users, user->fd);

  swrite(fd, "Good bye fellow !\r\n");
  close(fd);
  serv->fd_type[fd] = FD_FREE;
  printf("Connection close from fd n°%d\n", fd);
}

void		kill(t_server *serv, t_user *user, char *cmd)
{
  t_user	*tokill;
  char		*nick;
  char		ret[512];

  if ((nick = split_string(cmd, ' ', 1)) != NULL)
    {
      if (strcmp(user->nick, "Kafei") == 0)
	{
	  if ((tokill = get_user_by_nick(serv->users, nick)) != NULL)
	    {
	      sprintf(ret, ":%s KILL %s\r\n", user->nick, tokill->nick);
	      broadcast(serv, user, ret);
	      swrite(tokill->fd, "Killed by Admin\r\n");
	      quit(serv, tokill, NULL);
	    }
	  else
	    swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
	}
      else
	swrite(user->fd, "481 ERR_NOPRIVILEGES :Permission denied\r\n");
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}
