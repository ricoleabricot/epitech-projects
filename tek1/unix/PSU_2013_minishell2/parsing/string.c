/*
** string.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb 25 22:58:57 2014 Pierrick Gicquelais
** Last update Thu Mar  6 13:41:36 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

char		*my_strlcpy(char *str, int start)
{
  char		*cpy;
  int		i;
  int		j;

  i = start;
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

char		*my_strdup(char *str, int start)
{
  char		*cpy;
  int		i;
  int		j;

  i = start;
  j = 0;
  if ((cpy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    my_error("Error 113: Error with a memory allocation", 113);
  while (str[i] && str[i + 1] != '<' &&					\
	 str[i + 1] != '>' && str[i + 1] != '|' && str[i + 1] != ';')
    {
      cpy[j] = str[i];
      i++;
      j++;
    }
  cpy[j] = '\0';
  return (cpy);
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

int		my_strncmp(char *s1, char *s2, int nb)
{
  int		i;
  int		res;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < nb)
    i++;
  if (i == nb)
    return (0);
  else
    {
      res = s1[i] - s2[i];
      return (res);
    }
}

char		*my_strcat(char *dest, char *src)
{
  char		*str;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  if ((str = malloc							\
       ((my_strlen(src) + my_strlen(dest) + 2) * sizeof(char))) == NULL)
    my_error("Error 124: Error with a memory allocation", 124);
  while (dest[i])
    str[k++] = dest[i++];
  if (dest[i - 1] != '/')
    str[k++] = '/';
  while (src[j])
    str[k++] = src[j++];
  str[k] = '\0';
  return (str);
}
