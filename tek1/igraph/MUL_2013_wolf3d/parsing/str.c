/*
** str.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jan  5 23:26:51 2014 Pierrick Gicquelais
** Last update Sun Jan 12 16:41:51 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../include/wolf.h"

void		my_putchar(char c)
{
  write (1, &c, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
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

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
