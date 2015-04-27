/*
** myprintf.c for my_printf in /home/gicque_p/local/unix/PSU_2018_my_printf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov  4 16:01:19 2013 Pierrick Gicquelais
** Last update Tue Nov 26 18:49:19 2013 Pierrick Gicquelais
*/

#include "../my_ls.h"

void	check_option(char option, va_list ap)
{
  option_nbr(option, ap);
  option_string(option, ap);
  option_char(option, ap);
  if (option == '%')
    my_my_putchar('%', 0);
}

int	check_char(const char *str)
{
  int	i;
  int	cmp;

  i = 0;
  cmp = 0;
  while (str[i])
    {
      if (str[i] == '%' && str[i + 1] != '\0')
	cmp++;
      i++;
    }
  return (cmp);
}

int	my_printf(const char *format, ...)
{
  va_list	ap;
  int		nbarg;
  int		i;
  int		j;

  my_int_putchar(1);
  i = 0;
  j = 0;
  nbarg = check_char(format);
  va_start(ap, format);
  while (i++ <= nbarg)
    {
      while (format[j] != '%' && format[j])
	{
	  my_my_putchar(format[j], 0);
	  j++;
	}
      j++;
      check_option(format[j], ap);
      j++;
    }
  va_end(ap);
  i = my_int_putchar(0);
  my_int_putchar(1);
  return (i - 1);
}
