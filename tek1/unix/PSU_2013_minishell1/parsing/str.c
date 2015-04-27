/*
** str.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Dec 11 14:40:22 2013 Pierrick Gicquelais
** Last update Sat Dec 21 16:47:34 2013 Pierrick Gicquelais
*/

#include	"../shell.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str[i])
    while (str[i])
      i++;
  return (i);
}

void		my_error(char *s)
{
  my_putstr(s);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}

void		my_spec_error(char *s)
{
  my_putstr("If '");
  my_putstr(s);
  my_putstr("' is not a typo you can use command-not-found to lookup ");
  my_putstr("the package that contains it, like this :\n");
  my_putstr("\t cnf ");
  my_error(s);
}
