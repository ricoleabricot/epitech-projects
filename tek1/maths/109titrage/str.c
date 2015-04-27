/*
** str.c for 109titrage in /home/gicque_p/local/maths/109titrage
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 24 09:52:21 2014 Pierrick Gicquelais
** Last update Mon Mar 24 10:09:11 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"titrage.h"

char            *my_strcpy(char *str)
{
  char          *cpy;
  int           i;
  int           j;

  i = 0;
  j = 0;
  if ((cpy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    my_error("Error 113: Error with a memory allocation", 113);
  while (str[i])
    {
      cpy[j] = str[i];
      i++;
      j++;
    }
  cpy[j] = '\0';
  return (cpy);
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void		my_error(char *s, int error)
{
  printf("%s\n", s);
  exit(error);
}
