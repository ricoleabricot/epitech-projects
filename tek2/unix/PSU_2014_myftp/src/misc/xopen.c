/*
** xopen.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 15:15:01 2015 Pierrick Gicquelais
** Last update Tue Mar 17 15:16:04 2015 Pierrick Gicquelais
*/

#include	"xopen.h"
#include	"merror.h"

int		xopen(const char *pathname, int flags, mode_t mode)
{
  int		ret;

  if ((ret = open(pathname, flags, mode)) == -1)
    merror("Open Error");
  return (ret);
}
