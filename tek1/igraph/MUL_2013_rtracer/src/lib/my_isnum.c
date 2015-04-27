/*
** my_isnum.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 17:16:33 2014 Pierrick Gicquelais
** Last update Mon May 12 18:08:28 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_isnum(char *s)
{
  int		i;

  i = 0;
  if (s[i] == '-')
    i++;
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}
