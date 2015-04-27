/*
** xconnect.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:27 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:30 2015 Pierrick Gicquelais
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

