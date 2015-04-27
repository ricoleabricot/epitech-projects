/*
** my_env_to_wordtab.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Dec 19 22:49:36 2013 Pierrick Gicquelais
** Last update Mon Mar  3 12:56:04 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		env_len(char *str)
{
  int		n;

  n = 0;
  while (str[n] != '\0' && str[n] != ':')
    n++;
  return (n);
}

int		env_count(char *str)
{
  int		cmp;
  int		nb;

  cmp = 0;
  nb = 0;
  while (str[nb] != '\0')
    {
      if (str[nb] == ':' && str[nb + 1] != '\0')
        cmp++;
      nb++;
    }
  return (cmp);
}

char		**my_env_to_wordtab(char *str)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 4;
  j = 0;
  k = 0;
  tab = malloc((env_count(str) + 2) * sizeof(char *));
  while (str[i] != '\0')
    {
      if (str[i++] == ':')
        {
          j++;
          k = 0;
        }
      tab[j] = malloc((env_len(str + i) + 1) * sizeof(char) + 1);
      while (str[i] != ':' && str[i])
        tab[j][k++] = str[i++];
      tab[j][k++] = '/';
      tab[j][k] = '\0';
    }
  tab[j + 1] = NULL;
  return (tab);
}
