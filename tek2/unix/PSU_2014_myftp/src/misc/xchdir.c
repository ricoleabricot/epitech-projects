/*
** xchdir.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 11:41:33 2015 Pierrick Gicquelais
** Last update Tue Mar 17 11:42:16 2015 Pierrick Gicquelais
*/

#include	"xchdir.h"
#include	"merror.h"

int		xchdir(const char *path)
{
  int		ret;

  if ((ret = chdir(path)) == -1)
    merror("Chdir Error");
  return (ret);
}
