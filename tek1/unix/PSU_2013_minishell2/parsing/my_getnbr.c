/*
** my_getnbr.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 15:40:19 2014 Pierrick Gicquelais
** Last update Mon Mar  3 12:54:21 2014 Pierrick Gicquelais
*/

#include	"shell2.h"

int		my_getnbr(char *str)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  if (str[0] && str[0] == '-')
    i++;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      n = n + str[i] - 48;
      n = n * 10;
      i++;
    }
  n /= 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}
