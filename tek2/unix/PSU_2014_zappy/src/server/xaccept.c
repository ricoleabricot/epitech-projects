/*
** xaccept.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 09:47:20 2015 Pierrick Gicquelais
** Last update Fri Jun 19 09:51:28 2015 Pierrick Gicquelais
*/

#include	"server/xaccept.h"

int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int		ret;

  if ((ret = accept(sockfd, addr, addrlen)) == -1)
    merror("Accept Error");
  return (ret);
}
