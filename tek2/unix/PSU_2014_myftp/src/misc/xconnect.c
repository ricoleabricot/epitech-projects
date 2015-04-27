/*
** xconnect.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 16:41:27 2015 Pierrick Gicquelais
** Last update Fri Mar 13 16:42:20 2015 Pierrick Gicquelais
*/

#include	"xconnect.h"
#include	"merror.h"

int		xconnect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  int		ret;

  if ((ret = connect(sockfd, addr, addrlen)) == -1)
    {
      close(sockfd);
      merror("Connect Error");
    }
  return (ret);
}

