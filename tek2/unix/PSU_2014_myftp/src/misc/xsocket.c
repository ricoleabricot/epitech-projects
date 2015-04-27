/*
** xsocket.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:35:02 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:40:52 2015 Pierrick Gicquelais
*/

#include	"xsocket.h"
#include	"merror.h"

int		xsocket(int domain, int type, int protocol)
{
  int		ret;

  if ((ret = socket(domain, type, protocol)) == -1)
    merror("Socket Error");
  return (ret);
}
