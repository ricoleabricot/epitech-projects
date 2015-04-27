/*
** xaccept.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:34:12 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:52:11 2015 Pierrick Gicquelais
*/

#include	"xaccept.h"
#include	"merror.h"

int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int		ret;

  if ((ret = accept(sockfd, addr, addrlen)) == -1)
    {
      close(sockfd);
      merror("Accept Error");
    }
  return (ret);
}
