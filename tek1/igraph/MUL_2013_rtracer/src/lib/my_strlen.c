/*
** my_strlen.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:08:51 2014 Pierrick Gicquelais
** Last update Mon May 12 14:09:18 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}
