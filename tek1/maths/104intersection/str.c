/*
** str.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 17 21:31:12 2013 Pierrick Gicquelais
** Last update Thu Dec 26 16:27:24 2013 Pierrick Gicquelais
*/

#include "section.h"

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
int	my_str_isnum(char *str)
{
  int	i;
  int	j;

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
