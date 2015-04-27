/*
** put.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select/string
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jan 16 19:45:08 2014 Pierrick Gicquelais
** Last update Sat Jan 18 09:48:01 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../select.h"

int		my_putchar(int c)
{
  return (write(0, &c, 1));
}

void		my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void		my_put_spec_str(char *str, int background)
{
  if (background == 0)
    while (*str)
      {
	my_putchar(*str);
	str++;
      }
}

void		my_putstr_final(char *str)
{
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}

void		my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}
