/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/gicque_p/piscine/piscine8/ex_04
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Oct 10 10:28:21 2013 Pierrick Gicquelais
** Last update Wed Mar  5 11:30:32 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		word_len(char *str, int i)
{
  int		cmp;

  cmp = 0;
  while (str[i] && str[i] != ' ')
    {
      cmp++;
      i++;
    }
  return (cmp);
}

int		word_count(char *str)
{
  int		i;
  int		cmp;

  i = 0;
  cmp = 1;
  while (str[i])
    {
      if (str[i] == ' ')
	cmp++;
      i++;
    }
  return (cmp);
}

char		**my_str_to_wordtab(char *s, int *pos)
{
  char          **tab;
  int		i;
  int           j;
  int           k;

  i = *pos;
  j = 0;
  tab = malloc((word_count(s) + 1) * sizeof(char *));
  while (s[i] && s[i] != ';' && s[i] != '>' && s[i] != '<' && s[i] != '|')
    {
      k = 0;
      tab[j] = malloc((word_len(s, i) + 1) * sizeof(char));
      while (s[i] && s[i] != ' ')
	tab[j][k++] = s[i++];
      while (s[i] == ' ')
	i++;
      tab[j][k] = '\0';
      j++;
    }
  tab[j] = '\0';
  *pos = i + 1;
  return (tab);
}
