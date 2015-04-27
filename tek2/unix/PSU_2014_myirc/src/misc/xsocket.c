/*
** xsocket.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:50 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:51 2015 Pierrick Gicquelais
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
