/*
** mode_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:43:31 2015 Pierrick Gicquelais
** Last update Wed Apr 15 14:13:42 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"swrite.h"

static void	setmode(t_user *user, t_channel *ch, char *mode)
{
  char		ret[512];

  sprintf(ret, ":%s MODE %s\r\n", user->nick, mode);
  if (strcasecmp(mode, PRIVATE) == 0)
    {
      ch->private = true;
      swrite(user->fd, ret);
    }
  else if (strcasecmp(mode, PUBLIC) == 0)
    {
      ch->private = false;
      swrite(user->fd, ret);
    }
  else
    swrite(user->fd, "472 ERR_UNKNOWNMODE :Unknown mode flag\r\n");
}

void		mode(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;
  char		*mode;

  if (user->ch != NULL)
    {
      mode = split_string(cmd, ' ', 1);
      if (mode != NULL)
	{
	  ch = get_channel_by_name(serv->channels, user->ch);
	  if (op_exists(ch->ops, user->nick))
	    setmode(user, ch, mode);
	  else
	    swrite(user->fd, "481 ERR_NOPRIVILEGES :Permission denied\r\n");
	  free(mode);
	}
      else
	swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
    }
  else
    swrite(user->fd, "442 ERR_NOTONCHANNEL :You're not in a channel\r\n");
}
