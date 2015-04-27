/*
** str.c for 108monstre in /home/gicque_p/local/maths/108monstre
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 17 16:51:35 2014 Pierrick Gicquelais
** Last update Mon Mar 17 17:13:15 2014 Pierrick Gicquelais
*/

#include	"monstre.h"

int		my_strisnum(char *str)
{
  int		i;
  int		flag;

  i = 0;
  flag = 0;
  while (str[i])
    {
      if (str[i] == '.')
	{
	  i++;
	  flag++;
	}
      if ((str[i] < '0' || str[i] > '9') || flag > 1)
	return (1);
      i++;
    }
  return (0);
}
