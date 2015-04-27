/*
** my_put_nbr.c for my_put_nbr in /home/gicque_p/piscine/piscine3
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Oct  2 17:47:41 2013 Pierrick Gicquelais
** Last update Tue Feb 25 16:43:31 2014 Pierrick Gicquelais
*/

#include	"myprintf.h"

int		my_my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_my_putchar('-', 0);
      nb = -1 * nb;
    }
  if (nb >= 10)
    my_my_put_nbr(nb / 10);
  my_my_putchar(nb % 10 + 48, 0);
  return (nb);
}

unsigned int	my_put_nbr_unsign(unsigned nb)
{
  if (nb >= 10)
    my_my_put_nbr(nb / 10);
  my_my_putchar(nb % 10 + 48, 0);
  return (nb);
}

unsigned int	my_put_nbr_bin(unsigned nb)
{
  if (nb >= 2)
    my_put_nbr_bin(nb / 2);
  my_my_putchar(nb % 2 + 48, 0);
  return (nb);
}

unsigned int	my_put_nbr_octal(unsigned nb)
{
  if (nb >= 8)
    my_put_nbr_octal(nb / 8);
  my_my_putchar(nb % 8 + 48, 0);
  return (nb);
}

unsigned int	my_put_nbr_hexa(unsigned int nb, char option)
{
  if (nb >= 16)
    my_put_nbr_hexa(nb / 16, option);
  if (nb % 16 < 10)
    my_my_putchar(nb % 16 + 48, 0);
  else
    my_my_putchar(nb % 16 + option - 33, 0);
  return (nb);
}
