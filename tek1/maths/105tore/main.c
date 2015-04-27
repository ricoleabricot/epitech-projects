/*
** main.c for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 08:54:44 2014 Pierrick Gicquelais
** Last update Mon Jan 13 09:55:37 2014 Pierrick Gicquelais
*/

#include	"tore.h"

int		main(int argc, char **argv)
{
  if (argc < 8)
    my_few_error(argc);
  if (argc > 8)
    my_many_error(argc);
  if (atoi(argv[1]) != 1 && atoi(argv[1]) != 2 && atoi(argv[1]) != 3)
    my_choice_error(argv);
  my_number_error(argc, argv);
  printf("\033[01;37m");
  option_choice(argv);
  printf("\033[0;37m");
  return (0);
}
