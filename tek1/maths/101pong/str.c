/*
** str.c for 101pong in /home/gicque_p/local/maths/101pong
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Nov  9 13:33:48 2013 Pierrick Gicquelais
** Last update Sat Nov  9 14:13:05 2013 Pierrick Gicquelais
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
