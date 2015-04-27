/*
** my_strcat.c for rpg in /home/gicque_p/rendu/MUL_2013_rtracer
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun May 11 14:27:27 2014 Pierrick Gicquelais
** Last update Mon May 12 14:11:13 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strcat(char *str1, char *str2)
{
  char		*str;
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (NULL);
  i = my_strlen(str1) + my_strlen(str2) + 1;
  if ((str = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = 0;
  while (*str1 != '\0')
    str[i++] = *str1++;
  while (*str2 != '\0')
    str[i++] = *str2++;
  str[i] = '\0';
  return (str);
}
