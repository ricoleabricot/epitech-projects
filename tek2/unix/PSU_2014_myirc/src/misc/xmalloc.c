/*
** xmalloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:46 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:46 2015 Pierrick Gicquelais
*/

#include	"xmalloc.h"
#include	"merror.h"

void		*xmalloc(size_t size)
{
  void		*ret;

  if ((ret = malloc(size)) == NULL)
    merror("Malloc Error");
  return (ret);
}
