/*
** my_strncpy.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:13:20 2014 Pierrick Gicquelais
** Last update Tue May 13 12:14:24 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_strncpy(char *dest, char *src, char *delim, int start)
{
  int		i;

  i = start;
  if (dest == NULL || src == NULL)
    exit(EXIT_FAILURE);
  while (src[i] && src[i] != delim[0] && src[i] != delim[1])
    {
      dest[i - start] = src[i];
      i++;
    }
  dest[i - start] = '\0';
  return (0);
}

