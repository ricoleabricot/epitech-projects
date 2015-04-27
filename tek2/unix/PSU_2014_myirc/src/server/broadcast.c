/*
** broadcast.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 19:14:10 2015 Pierrick Gicquelais
** Last update Sat Apr 11 18:15:43 2015 Pierrick Gicquelais
*/

#include	"broadcast.h"
#include	"user.h"
#include	"swrite.h"

static void	circular_buffering(char *str, int fd)
{
  int		len;
  int		len2;

  len = strlen(str);
  len2 = 0;
  while (len2 != len)
    {
      len -= len2;
      len2 = swrite(fd, str + len2);
    }
}

void	        broadcast(t_server *serv, t_user *user, char *cmd)
{
  t_user	*tmp;
  int		i;

  i = 0;
  while (i < FD_MAX)
    {
      if (serv->fd_type[i] == FD_CLIENT && i != user->fd)
	{
	  tmp = get_user_by_fd(serv->users, i);
	  if (tmp->ch != NULL && user->ch && strcmp(user->ch, tmp->ch) == 0)
	    circular_buffering(cmd, i);
	}
      i++;
    }
}
