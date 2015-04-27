/*
** str.c for bsq in /home/gicque_p/local/cpe/CPE_2013_BSQ
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  8 14:40:06 2013 Pierrick Gicquelais
** Last update Sun Dec  8 18:08:20 2013 Pierrick Gicquelais
*/

#include "bsq.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void	my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit (0);
}

int	my_strlen(char *str)
{
  int	i;

  while (str[i])
    i++;
  return (i);
}
