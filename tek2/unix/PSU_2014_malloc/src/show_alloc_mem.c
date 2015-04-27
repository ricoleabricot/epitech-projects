/*
** show_alloc_mem.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 17:04:13 2015 Pierrick Gicquelais
** Last update Wed Feb 11 14:54:00 2015 Christian Boisson
*/

#include	"show_alloc_mem.h"

void		show_alloc_mem(void)
{
  size_t	*start;
  size_t	*end;
  size_t	*current;
  size_t	size;

  if ((current = heap_start()) != NULL)
    {
      printf("break: %p\n", current);
      start = heap_start();
      end = heap_end();
      if (start != end)
	if (end != NULL)
	  while (current < end)
	    {
	      size = (*current & ~1);
	      if (*current & 1)
		printf("%p - %p: %ld bytes\n", current + 1, \
		       (char *)current + size, size - HEAP_SIZE(sizeof(size_t)));
	      current = (size_t *)((char *)current + size);
	    }
    }
}
