/*
** str.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar 20 10:06:33 2014 Pierrick Gicquelais
** Last update Tue Apr  8 14:34:05 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"

void		my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  if (nbr / 10 > 0)
    my_putnbr(nbr / 10);
  my_putchar(nbr % 10 + 48);
}
