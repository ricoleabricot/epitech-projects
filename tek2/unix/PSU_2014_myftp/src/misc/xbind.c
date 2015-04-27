/*
** xbind.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:34:00 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:46:03 2015 Pierrick Gicquelais
*/

#include	"xbind.h"
#include	"merror.h"

int		xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  int		ret;

  if ((ret = bind(sockfd, addr, addrlen)) == -1)
    {
      close(sockfd);
      merror("Bind Error");
    }
  return (ret);
}

