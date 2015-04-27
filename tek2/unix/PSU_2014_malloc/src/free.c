/*
** free.c for free in /home/boisso_c/rendu/PSU_2014_malloc/src
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Wed Feb  4 11:54:53 2015 Christian Boisson
** Last update Thu Feb 12 13:05:06 2015 Christian Boisson
*/

#include		<pthread.h>
#include		"free.h"
#include		"heap.h"
#include		"show_alloc_mem.h"

extern pthread_mutex_t	mutex;

size_t			*last_before(size_t *ptr)
{
  size_t		*tmp;
  size_t		*last;

  tmp = heap_start();
  last = NULL;
  if (tmp != NULL)
    {
      while (tmp < ptr)
	{
	  if (*tmp & 1U)
	    {
	      tmp = (size_t *)((char *)tmp + (*tmp & ~1));
	      last = tmp;
	    }
	  else
	    tmp = (size_t *)((char *)tmp + (*tmp & ~1));
	}
    }
  return (last);
}

void			concat(size_t *ptr)
{
  size_t		*next;
  size_t		*end;

  end = heap_end();
  if (ptr != NULL && end != NULL && ptr != end)
    {
      next = (size_t *)((char *)ptr + (*ptr & ~1));
      if (next < end)
	if (!(*next & 1U))
	  *ptr += *next;
    }
}

int			can_brk(size_t *ptr)
{
  size_t		*tmp;
  size_t		*end;

  end = heap_end();
  if (end != NULL)
    {
      tmp = ptr;
      while (end && ptr && tmp != end && (*tmp & ~1))
	{
	  if (*tmp & 1U)
	    return (0);
	  tmp = (size_t *)((char *)tmp + (*tmp & ~1));
	}
      return (1);
    }
  return (0);
}

void			free(void *ptr)
{
  size_t		*to_free;
  size_t		*back;
  size_t		*tmp_back;

  if (ptr != NULL)
    {
      pthread_mutex_lock(&mutex);
      to_free = (size_t *)((char *)ptr - HEAP_SIZE(sizeof(size_t)));
      *(to_free) = *(to_free) & ~1;
      if (can_brk(to_free))
      	{
      	  if (brk(to_free) == -1)
      	    perror("Error");
      	  if ((back = last_before(to_free)) != NULL && back != heap_end())
      	    {
      	      tmp_back = (size_t *)((char *)back + (*back & ~1));
      	      if (tmp_back != NULL && tmp_back < heap_end() \
      		  && !(*tmp_back & 1U) && brk(to_free) == -1)
      		perror("Error");
      	    }
      	  concat(to_free);
      	  concat(back);
      	}
      pthread_mutex_unlock(&mutex);
    }
}
