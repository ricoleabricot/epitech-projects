/*
** name_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Apr 15 15:01:17 2015 Pierrick Gicquelais
** Last update Wed Apr 15 15:06:25 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"split_string.h"
#include	"swrite.h"

static void	aff_names(t_server *serv, t_user *user, t_channel *ch)
{
  char		*name;

  name = get_users_name(serv->users, ch);
  swrite(user->fd, name);
  swrite(user->fd, "\r\n");
  swrite(user->fd, "366 RPL_ENDOFNAMES :End of /NAMES list\r\n");
  free(name);
}

void		names(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*chan;
  char		*ch;
  char		ret[512];

  if ((ch = split_string(cmd, ' ', 1)) != NULL)
    {
      if ((chan = get_channel_by_name(serv->channels, ch)) != NULL)
	aff_names(serv, user, chan);
      else
	swrite(user->fd, "403 ERR_NOSUCHCHANEL :No such channel\r\n");
    }
  else
    {
      if (user->ch != NULL)
	{
	  sprintf(ret, "/names %s", user->ch);
	  names(serv, user, ret);
	}
      else
	swrite(user->fd, "461 ERR_USERNOTINCHAN :You're not in a channel\r\n");
    }
}
