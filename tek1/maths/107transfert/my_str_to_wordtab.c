/*
** my_str_to_wordtab.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar  6 15:23:18 2014 Pierrick Gicquelais
** Last update Fri Mar  7 18:12:41 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

int		word_len(char *str, int i)
{
  int		cmp;

  cmp = 0;
  while (str[i] && str[i] != '|')
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
      if (str[i] == '|')
	cmp++;
      i++;
    }
  return (cmp);
}

char		**my_str_to_wordtab(char *s)
{
  char          **tab;
  int		i;
  int           j;
  int           k;

  i = 0;
  j = 0;
  tab = malloc((word_count(s) + 1) * sizeof(char *));
  while (s[i])
    {
      k = 0;
      tab[j] = malloc((word_len(s, i) + 1) * sizeof(char));
      while (s[i] && s[i] != '|')
	tab[j][k++] = s[i++];
      while (s[i] == '|')
	i++;
      tab[j][k] = '\0';
      j++;
    }
  tab[j] = '\0';
  return (tab);
}

int		*my_tab_to_int(char **tab, int size)
{
  int		*tab2;
  int		i;

  i = 0;
  tab2 = malloc(size * sizeof(int));
  while (tab[i])
    {
      tab2[i] = atoi(tab[i]);
      i++;
    }
  return (tab2);
}

int		*my_reverse_tab_to_int(char **tab, int size)
{
  int		*tab2;
  int		i;
  int		save_size;

  save_size = size;
  i = 0;
  tab2 = malloc(size * sizeof(int));
  while (i < save_size - 1)
    {
      tab2[i] = atoi(tab[size - 2]);
      i++;
      size--;
    }
  return (tab2);
}
