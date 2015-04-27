/*
** my_getnbr.c for my_getnbr in /home/gicque_p/piscine/piscine4
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Oct  4 16:32:12 2013 Pierrick Gicquelais
** Last update Sun Dec  8 17:03:09 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

int	my_getnbr(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  if (str[0] == '-')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	my_error("There must be only numbers in the file");
      n = n + str[i] - 48;
      n = n * 10;
      i++;
    }
  n = n / 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}
