/*
** error.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  8 13:46:40 2013 Pierrick Gicquelais
** Last update Sun Dec  8 13:47:18 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

void	my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit (0);
}
