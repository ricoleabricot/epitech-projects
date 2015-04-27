/*
** my_putchar.c for my_printf in /home/gicque_p/local/unix/PSU_2018_my_printf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov  4 15:42:15 2013 Pierrick Gicquelais
** Last update Mon Mar  3 15:37:58 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	"myprintf.h"

void		my_my_putchar(char c, int end)
{
  write(1, &c, 1);
  my_int_putchar(end);
}

int		my_int_putchar(int end)
{
  static int	nb_char = 0;

  if (end == 0)
    nb_char++;
  else if (end == 1)
    nb_char = 0;
  return (nb_char);
}

void		my_my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_my_putchar(str[i], 0);
      i++;
    }
}

void		my_putstr_octal(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  if (str[i] >= 0 && str[i] <= 7)
	    my_my_putstr("\\00");
	  if (str[i] >= 8 && str[i] < 32)
	    my_my_putstr("\\0");
	  my_put_nbr_octal(str[i]);
	  i++;
	}
      else
	{
	  my_my_putchar(str[i], 0);
	  i++;
	}
    }
}
