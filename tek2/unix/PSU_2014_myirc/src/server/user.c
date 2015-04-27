/*
** user.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:21:08 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:35:36 2015 Pierrick Gicquelais
*/

#include	"user.h"
#include	"xmalloc.h"
#include	"swrite.h"

t_user		*new_user(void)
{
  t_user	*user;

  user = xmalloc(sizeof(t_user));

  user->prev = NULL;
  user->next = NULL;

  user->fd = 0;
  user->ch = NULL;
  user->nick = NULL;

  user->username = NULL;
  user->host = NULL;
  user->servername = NULL;
  user->realname = NULL;

  memset(user->buf, 0, 512);
  user->buf_size = 0;

  return (user);
}

t_user		*append_user(t_user *old, int fd, char *nick)
{
  t_user	*new;

  new = new_user();

  if ((old = last_user(old)) != NULL)
    old->next = new;

  new->fd = fd;
  new->nick = strdup(nick);
  new->prev = old;
  new->next = NULL;

  return (new);
}

void		aff_users(t_user *user, char *nick, int fd)
{
  char		ret[124];
  int		cpt;

  user = first_user(user);
  cpt = 0;
  while (user != NULL)
    {
      if (strcmp(user->nick, nick) != 0)
	{
	  sprintf(ret, "393 RPL_USERS :%s\r\n", user->nick);
	  swrite(fd, ret);
	  cpt++;
	}
      user = user->next;
    }

  if (cpt == 0)
    swrite(fd, "395 RPL_NOUSERS :Nobody logged in\r\n");
}

void		free_user(t_user *user)
{
  if (user != NULL)
    {
      if (user->ch != NULL)
	free(user->ch);
      if (user->nick != NULL)
	free(user->nick);
      if (user->username != NULL)
	free(user->username);
      if (user->host != NULL)
	free(user->host);
      if (user->servername != NULL)
	free(user->servername);
      if (user->realname != NULL)
	free(user->realname);
      free(user);
    }
}

void		free_users(t_user *user)
{
  t_user	*tmp;

  user = first_user(user);
  while (user != NULL)
    {
      tmp = user;
      user = user->next;
      free_user(tmp);
    }
}
