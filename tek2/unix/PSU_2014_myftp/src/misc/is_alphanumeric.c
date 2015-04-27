/*
** is_alphanumeric.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar 18 11:55:06 2015 Pierrick Gicquelais
** Last update Tue Mar 24 17:44:38 2015 Pierrick Gicquelais
*/

#include	"is_alphanumeric.h"

bool	        is_alphanumeric(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != 10)
	return (false);
      i++;
    }
  return (true);
}
