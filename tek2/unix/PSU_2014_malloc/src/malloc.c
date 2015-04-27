/*
** malloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 17:03:40 2015 Pierrick Gicquelais
** Last update Thu Feb 12 13:05:17 2015 Christian Boisson
*/

#include	<pthread.h>
#include	"malloc.h"

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
  size_t	block;
  size_t	*header;

  pthread_mutex_lock(&mutex);
  heap_start();
  block = HEAP_SIZE(size + sizeof(size_t));
  header = find(block);
  header = NULL;
  if (header != NULL)
    *header = *header | 1;
  else
    {
      if ((header = sbrk(block)) == (void *)-1)
	{
	  perror("Error");
	  return (NULL);
	}
      else
	*header = block | 1;
    }
  pthread_mutex_unlock(&mutex);
  return ((size_t *)((char* )header + sizeof(size_t)));
}

void		*find(size_t size)
{
  size_t	*current;
  size_t	*end;

  current = heap_start();
  end = heap_end();
  while (end && current && current != end)
    {
      if (!(*current & 1) && *current >= size)
	return current;
      else
	current = (size_t *)((char *)current + (*current & ~1));
    }
  return (NULL);
}
