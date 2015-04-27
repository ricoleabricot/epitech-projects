/*
** other_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 19:18:16 2015 Pierrick Gicquelais
** Last update Wed Apr 15 23:16:43 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"swrite.h"

void	        msg(t_server *serv, t_user *user, char *cmd)
{
  t_user	*tomsg;
  char		*nick;
  char		*message;
  char		ret[512];

  nick = split_string(cmd, ' ', 1);
  message = split_string(cmd, ' ', 2);
  if (nick != NULL && message != NULL)
    {
      tomsg = get_user_by_nick(serv->users, nick);
      if (tomsg != NULL)
	{
	  sprintf(ret, ":%s MSG %s\r\n", user->nick, message);
	  swrite(tomsg->fd, ret);
	}
      else
	swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

static void	kick_user(t_server *serv, t_user *user, char *nick, \
			  char *reason)
{
  t_user	*tokick;
  t_channel	*ch;
  char		ret[512];

  ch = get_channel_by_name(serv->channels, user->ch);
  if (op_exists(ch->ops, user->nick))
    {
      tokick = get_user_by_nick(serv->users, nick);
      if (tokick != NULL && strcmp(tokick->ch, user->ch) == 0)
	{
	  sprintf(ret, ":%s KICK %s :%s\r\n", user->nick, \
		  tokick->nick, reason);
	  part(serv, tokick, NULL);
	  swrite(tokick->fd, ret);
	}
      else
	swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
    }
  else
    swrite(user->fd, "481 ERR_NEEDMOREPARAMS :Permision denied\r\n");
}

void		kick(t_server *serv, t_user *user, char *cmd)
{
  char		*nick;
  char		*reason;

  nick = split_string(cmd, ' ', 1);
  reason = split_string(cmd, ' ', 2);

  if (user->ch != NULL)
    {
      if (nick != NULL)
	{
	  if (reason == NULL)
	    reason = strdup("no reason");
	  kick_user(serv, user, nick, reason);
	  free(nick);
	  free(reason);
	}
      else
	swrite(user->fd, "461 ERR_NEEDMOREPARAMS, :Not enough parameters\r\n");
    }
  else
    swrite(user->fd, "442 ERR_USERNOTINCHANNEL :You're not in a channel\r\n");
}

static void	invitation(t_server *serv, t_user *user, char *cmd)
{
  t_user	*toinvite;
  t_channel	*ch;
  char		*nick;
  char		ret[512];

  nick = split_string(cmd, ' ', 1);
  if (nick != NULL)
    {
      toinvite = get_user_by_nick(serv->users, nick);
      if (toinvite != NULL)
	{
	  ch = get_channel_by_name(serv->channels, user->ch);
	  ch->toinvite = strdup(nick);

	  sprintf(ret, ":%s INVITE %s :%s\r\n", \
		  user->nick, toinvite->nick, user->ch);
	  swrite(toinvite->fd, ret);
	}
      else
	swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
      free(nick);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

void		invite(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;

  if (user->ch != NULL)
    {
      ch = get_channel_by_name(serv->channels, user->ch);
      if (op_exists(ch->ops, user->nick))
	invitation(serv, user, cmd);
      else
	swrite(user->fd, "481 ERR_NOPRIVILEGES :Permission denied\r\n");
    }
  else
    swrite(user->fd, "442 ERR_USERNOTINCHANNEL :You're not in a channel\r\n");
}
