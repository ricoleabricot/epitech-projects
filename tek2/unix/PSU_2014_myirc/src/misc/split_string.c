/*
** split_string.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:59:57 2015 Pierrick Gicquelais
** Last update Wed Apr  8 15:05:29 2015 Gabriele Marsili
*/

#include	"split_string.h"
#include	"xmalloc.h"

static int	get_position(char *str, char d, int n)
{
  int		cpt;
  int		i;

  cpt = 0;
  i = 0;
  while (cpt != n)
    {
      while (str[i] && str[i] != d && str[i] != '\t')
	i++;
      i++;
      cpt++;
    }
  return (i);
}

char		*split_string(char *str, char d, int n)
{
  char		*newstr;
  int		i;
  int		j;
  int		size;

  if (str == NULL)
    return (NULL);
  newstr = xmalloc((strlen(str) + 1) * sizeof(char));
  memset(newstr, 0, strlen(str) + 1);
  i = get_position(str, d, n);
  j = 0;
  size = (int)strlen(str);
  while (i < size && str[i] && str[i] != d && str[i] != '\t')
    {
      newstr[j] = str[i];
      i++;
      j++;
    }
  newstr[j] = 0;
  if (newstr[0] == 0)
    return (NULL);
  return (newstr);
}
