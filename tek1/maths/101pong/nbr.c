/*
** my_put_nbr.c for my_put_nbr in /home/gicque_p/piscine/piscine3
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Oct  2 17:47:41 2013 Pierrick Gicquelais
** Last update Thu Dec 26 15:53:54 2013 Pierrick Gicquelais
*/

#include "main.h"

int	my_put_nbr(int nb)
{
  if (nb < -2147483647 || nb > 2147483647)
    return (0);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -1 * nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (nb);
}

unsigned int	my_put_nbr_octal(unsigned nb)
{
  if (nb >= 8)
    my_put_nbr_octal(nb / 8);
  my_putchar(nb % 8 + 48);
  return (nb);
}

unsigned int	my_put_nbr_hexa(unsigned nb)
{
  int	div;

  div = 1;
  while ((nb / div) >= 16)
    div = div * 16;
  while (div > 0)
    {
      if (nb >= 10)
	my_putchar((nb / div) % 16 + 87);
      else
	my_putchar((nb / div) % 16 + 48);
      div = div / 16;
    }
  return (nb);
}
