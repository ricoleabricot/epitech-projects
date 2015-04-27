/*
** realloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 17:04:01 2015 Pierrick Gicquelais
** Last update Thu Feb 12 13:00:42 2015 Christian Boisson
*/

#include	<stdio.h>
#include	<pthread.h>
#include	"malloc.h"
#include	"free.h"
#include	"realloc.h"

void		*realloc(void *ptr, size_t size)
{
  size_t	*tmp;
  size_t	*next;

  if (ptr != NULL)
    {
      tmp = (size_t *)ptr - 1;
      next = (size_t *)((char *)tmp + (*tmp & ~1));
      if (next != heap_end() && next < heap_end() && !(*next & 1))
      	{
      	  if ((*next & ~1) >= (size - (*tmp & ~1)))
	    *tmp = ((*tmp & ~1) + (*next & ~1)) | 1;
      	  else
	    ptr = set_alloc(ptr, size, (*tmp & ~1));
      	}
      else
	ptr = set_alloc(ptr, size, (*tmp & ~1));
    }
  else
    ptr = malloc(size);
  return (ptr);
}

void		*set_alloc(void *ptr, size_t size, size_t old_size)
{
  size_t	i;
  char		*new;
  char		*old;

  old  = (char *)ptr;
  new  = malloc(size + old_size);
  i = 0;
  while (i < old_size)
    {
      new[i] = old[i];
      ++i;
    }
  new[i] = 0;
  free(ptr);
  return (new);
}
