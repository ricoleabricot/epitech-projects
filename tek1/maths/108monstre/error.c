/*
** error.c for 108monstre in /home/gicque_p/local/maths/108monstre
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 10 08:55:06 2014 Pierrick Gicquelais
** Last update Mon Mar 17 16:57:36 2014 Pierrick Gicquelais
*/

#include	"monstre.h"

void		argc_error(int argc)
{
  printf("\033[01;31m");
  printf("You must enter only 2 arguments. ");
  if (argc < 2)
    printf("You must enter %d more argument(s) !\n", 2 - argc);
  else
    printf("You must enter %d less argument(s) !\n", argc - 2);
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		string_error(int arg)
{
  printf("\033[01;31m");
  printf("All arguments must be numbers, nethertheless, arg %d is not a number\n", arg);
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		first_arg_error()
{
  printf("\033[01;31m");
  printf("You must enter a value for 'a' (first arg) strict higher than 2 !\n");
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		second_arg_error()
{
  printf("\033[01;31m");
  printf("You must enter a value for 'nmax' (second arg) higher than 0 !\n");
  printf("\033[0m");
  exit(EXIT_FAILURE);
}
