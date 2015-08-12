/*
** xbind.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:16:52 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:55:32 2015 Pierrick Gicquelais
*/

#include	"server/xbind.h"

int	xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  int	ret;

  if ((ret = bind(sockfd, addr, addrlen)) == -1)
    merror("Bind Error");
  return (ret);
}
