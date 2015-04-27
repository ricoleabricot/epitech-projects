/*
** my_isnum.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 10 16:43:31 2014 Pierrick Gicquelais
** Last update Thu Apr 10 16:53:01 2014 Pierrick Gicquelais
*/

#include	"lib.h"

int		my_isnum(char *str)
{
  int		i;

  i = 0;
  if (str[0] && str[0] == '-' && str[1])
    i++;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}
