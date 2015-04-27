/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/gicque_p/piscine/piscine8/ex_04
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Oct 10 10:28:21 2013 Pierrick Gicquelais
** Last update Fri Dec  6 10:52:02 2013 Pierrick Gicquelais
*/

#include <stdlib.h>
#include "../include/fdf.h"

int	word_len(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0' && str[n] != ' ' && str[n] != '\n')
    n++;
  return (n);
}

int	word_count(char *str)
{
  int	cmp;
  int	nb;

  cmp = 0;
  nb = 0;
  while (str[nb] != '\0' && str[nb] != '\n')
    {
      if (str[nb] == ' ' && str[nb + 1] != '\0')
	cmp++;
      nb++;
    }
  return (cmp);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  k = 0;
  tab = malloc(((word_count(str) + 2)) * sizeof(*tab));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i] == ' ')
            i++;
          j = j + 1;
          k = 0;
        }
      tab[j] = malloc(((word_len(str + i) + 1)) * sizeof(**tab));
      while (str[i] != ' ' && str[i] != '\n' && str[i])
        tab[j][k++] = str[i++];
      tab[j][k] = '\0';
    }
  tab[j + 1] = '\0';
  return (tab);
}
