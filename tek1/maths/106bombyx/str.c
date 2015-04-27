/*
** str.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 11:55:00 2014 Pierrick Gicquelais
** Last update Sat Feb 15 11:52:32 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

void		my_putstr(char *s)
{
  while (*s)
    {
      my_putchar(*s);
      s++;
    }
}

void		my_error(char *s, int error)
{
  my_putstr("\033[01;31m");
  my_putstr(s);
  my_putchar('\n');
  my_putstr("\033[0m");
  exit(error);
}
