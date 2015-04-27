/*
** my_strcmp.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:11:57 2014 Pierrick Gicquelais
** Last update Mon May 12 14:11:58 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>

int	my_strcmp(char *str, char *str1)
{
  int		i;

  if (str == NULL || str1 == NULL)
    return (-1);
  i = 0;
  while (str[i] == str1[i] && str[i] != '\0')
    i++;
  return (!(str[i] == str1[i]));
}
