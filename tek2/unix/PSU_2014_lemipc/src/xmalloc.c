/*
** xmalloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 22:56:21 2015 Pierrick Gicquelais
** Last update Fri Feb 27 23:12:34 2015 Pierrick Gicquelais
*/

#include	"lemipc.h"
#include	"error.h"

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_error("Malloc Error");
  return (ptr);
}
