/*
** xaccept.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:17 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:17 2015 Pierrick Gicquelais
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
