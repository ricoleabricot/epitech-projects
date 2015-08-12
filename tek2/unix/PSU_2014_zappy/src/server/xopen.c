/*
** xopen.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jul  1 12:07:55 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:08:26 2015 Pierrick Gicquelais
*/

#include	"server/xopen.h"

int		xopen(const char *pathname, int flags, mode_t mode)
{
  int		ret;

  if ((ret = open(pathname, flags, mode)) == -2)
    merror("Open Error");
  return (ret);
}
