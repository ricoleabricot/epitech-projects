/*
** channel_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:34:50 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:54:54 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"broadcast.h"
#include	"swrite.h"

void		list(t_server *serv, t_user *user, char *cmd)
{
  char		*name;

  name = split_string(cmd, ' ', 1);
  swrite(user->fd, "321 RPL_LISTSTART :Channels name\r\n");
  aff_channels(serv->channels, name, user->fd);
  swrite(user->fd, "323 RPL_LISTEND :End of /LIST\r\n");

  if (name != NULL)
    free(name);
}

static void	togo(t_server *serv, t_user *user, t_channel *ch)
{
  char		ret[512];
  bool		invite;

  invite = false;
  if (!ch->private || op_exists(ch->ops, user->nick) || \
      (invite = is_invite(ch, user->nick)))
    {
      if (invite)
	ch->toinvite = NULL;

      if (user->ch != NULL)
	part(serv, user, NULL);
      user->ch = strdup(ch->name);
      sprintf(ret, "JOIN %s\r\n", user->ch);
      swrite(user->fd, ret);
      topic(serv, user, NULL);
      names(serv, user, user->ch);
      sprintf(ret, ":%s JOIN %s\r\n", user->nick, user->ch);
      broadcast(serv, user, ret);
    }
  else
    swrite(user->fd, \
	   "473 ERR_INVITEONLYCHAN :Cannot join private channel\r\n");
}

void	        join(t_server *serv, t_user *user, char *cmd)
{
  t_channel	*ch;
  char		*name;

  name = split_string(cmd, ' ', 1);
  if (name != NULL)
    {
      ch = get_channel_by_name(serv->channels, name);
      if (ch != NULL)
	togo(serv, user, ch);
      else
	swrite(user->fd, "403 ERR_NOSUCHCHANNEL :No such channel\r\n");
      free(name);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

void	        part(t_server *serv, t_user *user, char *cmd)
{
  char		ret[512];
  char		*tmp;

  (void)cmd;
  if (user->ch != NULL)
    {
      sprintf(ret, ":%s PART %s\r\n", user->nick, user->ch);
      broadcast(serv, user, ret);

      tmp = strdup(user->ch);
      user->ch = NULL;
      swrite(user->fd, "PART\r\n");

      if (channel_is_empty(serv->users, tmp) && tmp[0] != '#')
	serv->channels = pop_channel(serv->channels, tmp);

      free(tmp);
    }
  else
    swrite(user->fd, "442 ERR_NOTONCHANNEL :You're not in a channel\r\n");
}

void          create(t_server *serv, t_user *user, char *cmd)
{
  char    *name;
  char    ret[512];

  if ((name = split_string(cmd, ' ', 1)) != NULL)
    {
      if (strlen(name) < 64 && name[0] != '#' && name[0] != '~')
	{
	  if (!channel_exists(serv->channels, name))
	    {
	      sprintf(ret, "/join %s", name);
	      serv->channels = append_channel(serv->channels, name);
	      serv->channels->ops = append_op(serv->channels->ops, user->nick);
	      join(serv, user, ret);
	    }
	  else
	    swrite(user->fd, \
		   "475 ERR_BADCHANNELKEY :Channel already exists\r\n");
	}
      else
	swrite(user->fd, \
	       "481 ERR_NOPRIVILEGES :You can't create this server\r\n");
      free(name);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}
