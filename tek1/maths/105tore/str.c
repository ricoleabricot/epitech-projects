/*
** str.c for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 08:56:58 2014 Pierrick Gicquelais
** Last update Mon Jan 13 09:12:16 2014 Pierrick Gicquelais
*/

#include	"tore.h"

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

int		my_str_isnum(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str == 0)
    return (1);
  if (str[i] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (j > 1)
        return (0);
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
        {
          if (str[i] == '.')
            j++;
          i++;
        }
      else
        return (0);
    }
  return (1);
}
