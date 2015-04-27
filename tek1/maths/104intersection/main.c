/*
** main.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 17 21:30:52 2013 Pierrick Gicquelais
** Last update Sat Jan  4 21:47:18 2014 Pierrick Gicquelais
*/

#include "section.h"

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  if (argv[1])
    if (atof(argv[1]) == 1.1 || atof(argv[1]) == 2.1)
      my_bonus(argc, argv);
  if (argc < 9)
    my_few_error(argc);
  if (argc > 9)
    my_many_error(argc);
  while (++i < argc)
    if (my_str_isnum(argv[i]) == 0)
      my_number_error(i, argv);
  if (atof(argv[5]) == 0 && atof(argv[6]) == 0 && atof(argv[7]) == 0)
    my_vector_error();
  if ((atof(argv[1]) == 1 || atof(argv[1]) == 2) && atof(argv[8]) <= 0)
    my_radius_error();
  my_putstr("\033[01;37m");
  check_option(argv);
  my_putstr("\033[0;37m");
  return (0);
}
