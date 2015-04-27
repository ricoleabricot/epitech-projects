/*
** my_fputstr.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:06:38 2014 Pierrick Gicquelais
** Last update Mon May 12 18:14:23 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

void		my_fputstr(int fd, char *s)
{
  if (s == NULL)
    my_error("Can't write NULL");
  while (*s)
    my_fputchar(fd, *s++);
}
