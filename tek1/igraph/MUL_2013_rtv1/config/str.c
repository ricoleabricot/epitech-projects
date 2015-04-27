/*
** str.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Feb  7 09:36:56 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:38:14 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

void		my_putstr(char *s)
{
  while (*s)
    {
      my_putchar(*s);
      s++;
    }
}

void		my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

void		my_error(char *s, int error)
{
  my_putstr(s);
  my_putchar('\n');
  exit(error);
}
