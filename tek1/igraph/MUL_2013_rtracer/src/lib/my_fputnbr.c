/*
** my_fputnbr.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 16:40:46 2014 Pierrick Gicquelais
** Last update Mon May 12 16:41:56 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

void		my_fputnbr(int fd, int nb)
{
  if (nb / 10 > 0)
    my_fputnbr(fd, nb / 10);
  my_fputchar(fd, nb % 10 + 48);
}
