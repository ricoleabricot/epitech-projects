/*
** my_strndup.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:12:48 2014 Pierrick Gicquelais
** Last update Tue May 13 12:13:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strndup(char *str, char *delim, int start)
{
  char		*cpy;

  if (str == NULL)
    exit(EXIT_FAILURE);
  if ((cpy = malloc(((my_strlen(str) + 1) - start) * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  if (my_strncpy(cpy, str, delim, start))
    {
      free(cpy);
      exit(EXIT_FAILURE);
    }
  return (cpy);
}
