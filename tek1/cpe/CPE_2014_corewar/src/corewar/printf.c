/*
** printf.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Wed Mar 26 11:33:20 2014 Pierrick Gicquelais
** Last update Fri Apr  4 13:30:22 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"funct.h"

static void	check_option(char option, va_list ap)
{
  if (option == 'd')
    my_putnbr(va_arg(ap, int));
  else if (option == 's')
    my_putstr(va_arg(ap, char *));
  else if (option == 'c')
    my_putchar(va_arg(ap, int));
}

void		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (format[i])
    {
      while (format[i] && format[i] != '%')
	my_putchar(format[i++]);
      if (format[i] == '%')
	{
	  check_option(format[++i], ap);
	  i++;
	}
    }
  va_end(ap);
}
