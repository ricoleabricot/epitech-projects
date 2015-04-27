/*
** str.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec  2 17:27:52 2013 Pierrick Gicquelais
** Last update Fri Dec  6 17:28:35 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

int	my_abs(int nb)
{
  if (nb < 0)
    nb = nb * (-1);
  return (nb);
}

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    exit (0);
  while (str[i])
    i++;
  return (i);
}
