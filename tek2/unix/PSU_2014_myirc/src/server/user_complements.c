/*
** user_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:01:45 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:36:32 2015 Pierrick Gicquelais
*/

#include	"user.h"
#include	"op.h"

t_user		*get_user_by_fd(t_user *user, int fd)
{
  user = first_user(user);
  while (user != NULL)
    {
      if (user->fd == fd)
	return (user);
      user = user->next;
    }
  return (NULL);
}

t_user		*get_user_by_nick(t_user *user, char *nick)
{
  user = first_user(user);
  while (user != NULL)
    {
      if (strcmp(user->nick, nick) == 0)
	return (user);
      user = user->next;
    }
  return (NULL);
}

char		*get_users_name(t_user *users, t_channel *ch)
{
  char		*names;

  names = strdup("353 RPL_NAMREPLY =");
  names = realloc(names, strlen(names) + 1);
  users = first_user(users);
  while (users != NULL)
    {
      if (users->ch && strcmp(users->ch, ch->name) == 0)
	{
	  names = realloc(names, strlen(names) + strlen(users->nick) + 3);
	  if (op_exists(ch->ops, users->nick))
	    sprintf(names, "%s @%s", names, users->nick);
	  else
	    sprintf(names, "%s +%s", names, users->nick);
	}
      users = users->next;
    }

  return (names);
}

bool		user_exists(t_user *users, char *nick)
{
  users = first_user(users);
  while (users != NULL)
    {
      if (strcmp(users->nick, nick) == 0)
	return (true);
      users = users->next;
    }
  return (false);
}

bool		channel_is_empty(t_user *users, char *name)
{
  users = first_user(users);
  while (users != NULL)
    {
      if (users->ch != NULL && strcmp(users->ch, name) == 0)
	return (false);
      users = users->next;
    }
  return (true);
}
