/*
** error.c for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 09:03:19 2014 Pierrick Gicquelais
** Last update Mon Jan 13 09:53:38 2014 Pierrick Gicquelais
*/

#include	"tore.h"

void		my_error(char *s)
{
  my_putstr("\033[01;31m");
  my_putstr(s);
  my_putchar('\n');
  my_putstr("\033[0;37m");
  exit(EXIT_FAILURE);
}

void		my_few_error(int argc)
{
  printf("\033[01;31m");
  printf("Too few arguments. You must enter %d more argument(s) !\n", 8 - argc);
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void		my_many_error(int argc)
{
  printf("\033[01;31m");
  printf("Too many arguments. You must enter %d less argument(s) !\n", argc - 8);
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}

void		my_number_error(int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    if (my_str_isnum(argv[i]) == 0)
      {
	printf("\033[01;31m");
	printf("Arguments must be only numbers: Argument n°%d -> '%s' is not a number\n", i, argv[i]);
	printf("\033[0;37m");
	exit(EXIT_FAILURE);
      }
}

void		my_choice_error(char **argv)
{
  printf("\033[01;31m");
  printf("Argument n°1 -> '%s' is not a valide option.\nEnter '1' for a bissection choice, '2' for a Newton choice or '3' for a secante choice\n", argv[1]);
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}
