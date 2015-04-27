/*
** my_isneg.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 10 16:47:58 2014 Pierrick Gicquelais
** Last update Thu Apr 10 16:56:56 2014 Pierrick Gicquelais
*/

#include	"lib.h"

int		my_isneg(char *str)
{
  int		i;
  int		flag;

  i = 0;
  flag = 0;
  if (str[0] && str[0] == '-' && str[1])
    {
      i++;
      flag++;
    }
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  if (flag == 1)
    return (0);
  return (-1);
}
