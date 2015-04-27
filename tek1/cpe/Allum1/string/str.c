/*
** str.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  3 21:16:06 2014 Pierrick Gicquelais
** Last update Wed Feb 12 22:22:31 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int		my_putchar(int c)
{
  return (write(1, &c, 1));
}

void		my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

void		my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}
