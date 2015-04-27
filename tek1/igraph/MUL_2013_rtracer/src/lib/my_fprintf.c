/*
** printf.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Wed Mar 26 11:33:20 2014 Pierrick Gicquelais
** Last update Fri May  9 23:30:50 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"

static void	check_option(int fd, char option, va_list ap)
{
  if (option == 'd')
    my_fputnbr(fd, va_arg(ap, int));
  else if (option == 's')
    my_fputstr(fd, va_arg(ap, char *));
  else if (option == 'c')
    my_fputchar(fd, va_arg(ap, int));
}

void		my_fprintf(int fd, const char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (format[i])
    {
      while (format[i] && format[i] != '%')
	my_fputchar(fd, format[i++]);
      if (format[i] == '%')
	{
	  check_option(fd, format[++i], ap);
	  i++;
	}
    }
  va_end(ap);
}
