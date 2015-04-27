/*
** error.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Dec 26 16:13:58 2013 Pierrick Gicquelais
** Last update Sat Jan  4 20:45:00 2014 Pierrick Gicquelais
*/

#include "section.h"

void	my_error(char *s)
{
  my_putstr("\033[01;31m");
  my_putstr(s);
  my_putchar('\n');
  my_putstr("\033[0;37m");
  exit(EXIT_FAILURE);
}

void    my_few_error(int argc)
{
  printf("\033[01;31m");
  printf("Too few arguments. You must enter %d more argument(s) !", 9 - argc);
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void    my_many_error(int argc)
{
  printf("\033[01;31m");
  printf("Too many arguments. You must enter %d less argument(s) !", argc - 9);
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void    my_number_error(int i, char **argv)
{
  printf("\033[01;31m");
  printf("You must enter only numbers as arguments and argument n°%d -> '%s': is not a number", i, argv[i]);
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void    my_vector_error()
{
  printf("\033[01;31m");
  printf("You must enter a non-null vector. Division by zero !");
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void	my_radius_error()
{
  printf("\033[01;31m");
  printf("You must enter a strict positive value for a radius (option '1', '1.1' and '2')");
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}
