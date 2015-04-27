/*
** get_next_line.c for get_next_line.c in /home//rendu/CPE_2013_getnextline
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov 18 17:05:38 2013 Pierrick Gicquelais
** Last update Sun Dec  8 18:06:46 2013 Pierrick Gicquelais
*/

#include "bsq.h"

# define BUF_SIZE (1)

char		*re_alloc(char *str)
{
  char		*str2;
  int		i;

  i = 0;
  if ((str2 = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    my_error("Error with an allocation");
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i++;
    }
  str2[i + 1] = '\0';
  free(str);
  return (str2);
}

char		*get_next_line(const int fd)
{
  int		i;
  int		size;
  static char	buf[BUF_SIZE];
  char		*str;

  i = 0;
  size = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    my_error("Error with an allocation");
  str[0] = '\0';
  while ((size = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
    {
      str = re_alloc(str);
      str[i] = buf[0];
      i++;
    }
  if (size == 0 && i == 0)
    return (NULL);
  else
    return (str);
}
