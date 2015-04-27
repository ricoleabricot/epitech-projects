/*
** mod_str.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Dec 18 11:51:30 2013 Pierrick Gicquelais
** Last update Thu Dec 19 23:33:12 2013 Pierrick Gicquelais
*/

#include	"../shell.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;
  int		k;
  char		*str;

  i = 0;
  j = 0;
  k = 0;
  if ((str = malloc((my_strlen(src) + my_strlen(dest) + 2) \
                    * sizeof(char))) == NULL)
    exit (0);
  while (dest[i])
    str[k++] = dest[i++];
  if (dest[i - 1] != '/')
    str[k++] = '/';
  while (src[j])
    str[k++] = src[j++];
  str[k] = '\0';
  return (str);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (-1);
}
