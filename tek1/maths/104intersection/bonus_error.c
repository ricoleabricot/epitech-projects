/*
** bonus_error.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jan  4 20:34:19 2014 Pierrick Gicquelais
** Last update Sat Jan  4 20:40:03 2014 Pierrick Gicquelais
*/

#include "section.h"

void	my_bonus_few_error(int argc)
{
  printf("\033[01;31m");
  printf("Too few arguments. You must enter %d more argument(s) !", 12 - argc);
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);  
}

void	my_bonus_many_error(int argc)
{
  printf("\033[01;31m");
  printf("Too many arguments. You must enter %d less argument(s) !", argc - 12);
  printf("\n");
  printf("\033[0;37m");
  exit(EXIT_FAILURE);
}
