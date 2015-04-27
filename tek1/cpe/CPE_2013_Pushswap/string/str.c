/*
** str.c for pushswap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec 16 13:03:18 2013 Pierrick Gicquelais
** Last update Thu Jan  2 16:27:44 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
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
  if (nb < 0)
    {
      my_putchar('-');
      nb = -1 * nb;
    }
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (-1);
}

void		my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}
