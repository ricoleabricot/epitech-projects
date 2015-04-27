/*
** my_error.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 18:09:02 2014 Pierrick Gicquelais
** Last update Mon May 12 18:11:12 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

void		my_error(char *s)
{
  my_fprintf(2, "%s\n", s);
  exit(EXIT_FAILURE);
}
