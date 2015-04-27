/*
** operator_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:38:07 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:56:30 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"swrite.h"

static void	make_operator(t_server *serv, t_user *user, t_channel *ch, \
			      char *cmd)
{
  t_user	*toop;
  char		*nick;
  char		ret[512];

  nick = split_string(cmd, ' ', 1);
  if (nick != NULL)
    {
      toop = get_user_by_nick(serv->users, nick);
      if (toop != NULL)
	{
	  if (!op_exists(ch->ops, toop->nick))
	    {
	      ch->ops = append_op(ch->ops, toop->nick);
	      sprintf(ret, ":%s OP %s\r\n", user->nick, toop->nick);
	      swrite(toop->fd, ret);
	    }
	  else
	    swrite(user->fd, "433 ERR_NICKNAMEINUSE :User already op\r\n");
	}
      else
	swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
      free(nick);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

void		op(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;

  if (user->ch != NULL)
    {
      ch = get_channel_by_name(serv->channels, user->ch);
      if (op_exists(ch->ops, user->nick))
	make_operator(serv, user, ch, cmd);
      else
	swrite(user->fd, "481 ERR_NOPRIVILEGES :Permission denied\r\n");
    }
  else
    swrite(user->fd, "442 ERR_USERNOTINCHANNEL :You're not in a channel\r\n");
}

static void	demake_operator(t_server *serv, t_user *user, t_channel *ch, \
				char *cmd)
{
  t_user	*toop;
  char		*nick;
  char		ret[512];

  nick = split_string(cmd, ' ', 1);
  if (nick != NULL)
    {
      toop = get_user_by_nick(serv->users, nick);
      if (toop != NULL && op_exists(ch->ops, toop->nick))
	{
	  ch->ops = pop_op(ch->ops, nick);
	  sprintf(ret, ":%s DEOP %s\r\n", user->nick, toop->nick);
	  swrite(toop->fd, ret);
	}
      else
	swrite(user->fd, "401 ERR_NOSUCHNICK :No such op\r\n");
      free(nick);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

void	        deop(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;

  if (user->ch != NULL)
    {
      ch = get_channel_by_name(serv->channels, user->ch);
      if (op_exists(ch->ops, user->nick))
	demake_operator(serv, user, ch, cmd);
      else
	swrite(user->fd, "481 ERR_NOPRIVILEGES :Permission denied\r\n");
    }
  else
    swrite(user->fd, "442 ERR_USERNOTINCHANNEL:You're not in a channel\r\n");
}
