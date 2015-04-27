/*
** printf.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Wed Mar 26 11:33:20 2014 Pierrick Gicquelais
** Last update Fri Apr 11 09:40:09 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"funct.h"

static void	check_option(char option, va_list ap)
{
  int		nbr;
  char		*str;
  char		c;

  if (option == 'd')
    {
      nbr = va_arg(ap, int);
      my_putnbr(nbr);
    }
  else if (option == 's')
    {
      str = va_arg(ap, char *);
      my_putstr(str);
    }
  else if (option == 'c')
    {
      c = va_arg(ap, int);
      my_putchar(c);
    }
}

void		my_print_error(const char *format, ...)
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
  exit(EXIT_FAILURE);
}
