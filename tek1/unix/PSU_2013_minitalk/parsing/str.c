/*
** str.c for minitalk in /home/gicque_p/PSU_2013_minitalk
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 10:34:09 2014 Pierrick Gicquelais
** Last update Tue Mar 11 14:10:27 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  return (i);
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
