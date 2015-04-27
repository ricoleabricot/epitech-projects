/*
** str.c for 103architecte in /home/gicque_p/local/maths/103architecte
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec  9 09:46:52 2013 Pierrick Gicquelais
** Last update Wed Dec 11 12:46:39 2013 Pierrick Gicquelais
*/

#include "architecte.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void	my_error(char *s)
{
  printf("\033[01;31m%s\n", s);
  printf("\033[0;37m");
  exit (0);
}

void	check_error_one(char *str)
{
  if (my_str_isnum(str) == 0)
    my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
}

void	check_error_two(char *str)
{
  if (my_str_isnum(str) == 0)
    my_error("After option R or S, you must enter only on number\nExecute ./man_103 to read the man");
}
