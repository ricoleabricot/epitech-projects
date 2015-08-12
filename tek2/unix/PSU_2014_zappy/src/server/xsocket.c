/*
** xsocket.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:12:27 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:55:38 2015 Pierrick Gicquelais
*/

#include	"server/xsocket.h"

int		xsocket(int domain, int type, int protocol)
{
  int		ret;

  if ((ret = socket(domain, type, protocol)) == -1)
    merror("Socket Error");
  return (ret);
}
