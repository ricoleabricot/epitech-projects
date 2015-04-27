/*
** check.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb 12 10:33:34 2014 Pierrick Gicquelais
** Last update Wed Feb 19 19:50:44 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void		check_ex1(double k)
{
  if (k < 1.)
    my_error("Error 23: Rate growth too small.\nYou must enter a rate growth between 1 and 4", 23);
  else if (k > 4.)
    my_error("Error 24: Rate growth too high.\nYou must enter a rate growth between 1 and 4", 24);
}

void		check_ex2(double i_min, double i_max)
{
  if (i_max <= i_min)
    my_error("Error 25: Maximum (arg 2) must be strict higher than Minimum (Arg 1)", 25);
  else if (i_min <= 0)
    my_error("Error 26: Minimum (arg 1) must be strict higher than zero", 26);
}
