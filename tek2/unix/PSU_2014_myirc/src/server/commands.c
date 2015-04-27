/*
** commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 19:04:01 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:57:15 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"trim.h"
#include	"split_string.h"
#include	"broadcast.h"
#include	"xmalloc.h"
#include	"swrite.h"

static	char	(*g_str[25]) =
{
  SERVER,
  NICK,
  LIST,
  JOIN,
  PART,
  USERS,
  PRIVMSG,
  MSG,
  SEND,
  ACCEPT,
  NAMES,
  OPER,
  DEOPER,
  KICK,
  KILL,
  CREATE,
  INVITE,
  MODE,
  PASS,
  USER,
  ME,
  TOPIC,
  HELP,
  QUIT,
  NULL
};

static	void	(*g_fct[25])(t_server *, t_user *, char *) =
{
  &server,
  &nick,
  &list,
  &join,
  &part,
  &users,
  &msg,
  &msg,
  &send_file,
  &accept_file,
  &names,
  &op,
  &deop,
  &kick,
  &kill,
  &create,
  &invite,
  &mode,
  &pass,
  &user,
  &me,
  &topic,
  &help,
  &quit,
  NULL
};

static void	action_it(t_server *serv, t_user *user, char *trimstr, int i)
{
  char		ret[1024];

  if (g_str[i])
    (g_fct[i])(serv, user, trimstr);
  else if (user->ch != NULL)
    {
      sprintf(ret, ":%s PRIVMSG %s :%s\r\n", user->nick, user->ch, trimstr);
      broadcast(serv, user, ret);
    }
  else
    swrite(user->fd, "442 ERR_USERNOTINCHANNEL :You're not in a channel\r\n");
}

void		commands(t_server *serv, t_user *user, char *cmd)
{
  char		*trimstr;
  char		*token;
  int		i;

  trimstr = trim(cmd);
  if (trimstr)
    {
      token = split_string(trimstr, ' ', 0);
      if (token)
	{
	  i = 0;
	  while (g_str[i] && strcmp(g_str[i], token) != 0)
	    i++;
	  action_it(serv, user, trimstr, i);
	  free(token);
	}
      free(trimstr);
    }
}
