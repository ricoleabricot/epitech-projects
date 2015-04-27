/*
** error.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select/string
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jan 16 19:47:38 2014 Pierrick Gicquelais
** Last update Sun Jan 19 21:35:11 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"../select.h"

void		my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}
