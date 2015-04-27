/*
** str.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov 25 11:06:22 2013 Pierrick Gicquelais
** Last update Wed Nov 27 19:47:46 2013 Pierrick Gicquelais
*/

#include "main.h"

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
  while (str[i])
    i++;
  return (i);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
    {
      while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
	  if (str[i + 1] == '\0')
	    return (1);
	  i++;
	}
      return (0);
    }
  else
    return (0);
}
