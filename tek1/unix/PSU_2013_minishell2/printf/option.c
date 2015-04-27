/*
** option.c for myprintf in /home/gicque_p/local/unix/PSU_2018_my_printf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Nov 13 09:51:20 2013 Pierrick Gicquelais
** Last update Tue Feb 25 16:43:40 2014 Pierrick Gicquelais
*/

#include	"myprintf.h"

void		option_nbr(char option, va_list ap)
{
  int		arg;

  if (option == 'd' || option == 'i' || option == 'o' || option == 'x' || \
      option == 'X' || option == 'p' || option == 'b' || option == 'u')
    {
      arg = va_arg(ap, unsigned int);
      if (option == 'd' || option == 'i')
	my_my_put_nbr(arg);
      if (option == 'u')
	my_put_nbr_unsign(arg);
      else if (option == 'o')
	my_put_nbr_octal(arg);
      else if (option == 'x' || option == 'X')
	my_put_nbr_hexa(arg, option);
      else if (option == 'b')
	my_put_nbr_bin(arg);
      else if (option == 'p')
	{
	  my_my_putstr("0x7fff");
	  my_put_nbr_hexa(arg, 'x');
	}
    }
}

void		option_string(char option, va_list ap)
{
  char		*arg;

  if (option == 's' || option == 'S')
    {
      arg = va_arg(ap, char *);
      if (option == 's')
	my_my_putstr(arg);
      else if (option == 'S')
	my_putstr_octal(arg);
    }
}

void		option_char(char option, va_list ap)
{
  char		arg;

  if (option == 'c')
    {
      arg = va_arg(ap, int);
      my_my_putchar(arg, 0);
    }
}
