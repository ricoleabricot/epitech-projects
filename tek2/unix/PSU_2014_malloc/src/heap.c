/*
** heap.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 17:03:26 2015 Pierrick Gicquelais
** Last update Wed Feb 11 15:20:54 2015 Christian Boisson
*/

#include	"heap.h"

size_t		*heap_start()
{
  static size_t	*heap_start = NULL;

  if (heap_start == NULL)
    {
      if ((heap_start = sbrk(0)) == (void*) -1)
	{
	  perror("Error");
	  return NULL;
	}
    }
  return heap_start;
}

size_t		*heap_end()
{
  size_t	*heap_end = NULL;

  if ((heap_end = sbrk(0)) == (void*) -1)
    {
      perror("Error");
      return NULL;
    }
  return heap_end;
}
