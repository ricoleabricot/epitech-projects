/*
** my_getnbr.c for my_getnbr in /home/gicque_p/piscine/piscine4
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Oct  4 16:32:12 2013 Pierrick Gicquelais
** Last update Thu Nov 14 14:37:05 2013 Pierrick Gicquelais
*/

#include "main.h"

int	my_getnbr(char *str)
{
  int	i;
  int	n;
  int	signe;
  
  i = 0;
  n = 0;
  signe = 1;
  if (str[i] > -2147483647 && str[i] < 2147483647)
    {
      while (str[i] == '-' || str[i] == '+')
  	{
  	  if (str[i] == '-')
  	    signe = signe * (-1);
  	  i++;
  	}
      while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
  	{
  	  n = n * 10;
  	  n = n + str[i] - 48;
  	  i++;
  	}
      return (n * signe);
    }
  else
    return (0);
}
