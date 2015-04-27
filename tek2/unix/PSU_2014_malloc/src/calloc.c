/*
** calloc.c for calloc in /home/boisso_c/rendu/PSU_2014_malloc/src
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Feb  9 15:58:26 2015 Christian Boisson
** Last update Thu Feb 12 13:00:29 2015 Christian Boisson
*/

#include	<pthread.h>
#include	"calloc.h"


void		*calloc(size_t nmemb, size_t size)
{
  char		*tmp;
  size_t	i;
  size_t	total_size;

  total_size = HEAP_SIZE(size * nmemb);
  if ((tmp = malloc(total_size)) == NULL)
    return (NULL);
  i = 0;
  while (i < total_size)
    {
      tmp[i] = 0;
      ++i;
    }
  return (tmp);
}
