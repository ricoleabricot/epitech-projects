/*
** get_next_line.c for get_next_line.c in /home//rendu/CPE_2013_getnextline
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov 18 17:05:38 2013 Pierrick Gicquelais
** Last update Fri Mar 20 20:25:58 2015 Pierrick Gicquelais
*/

#include	"getnextline.h"
#include	"xmalloc.h"

static char	*re_alloc(char *oldstr, char buf)
{
  char		*newstr;
  int		i;

  i = 0;
  newstr = xmalloc((strlen(oldstr) + 2) * sizeof(char));
  while (oldstr[i])
    {
      newstr[i] = oldstr[i];
      i++;
    }
  newstr[i] = buf;
  newstr[++i] = 0;
  free(oldstr);

  return (newstr);
}

char		*getnextline(const int fd)
{
  static char	buf[BUF_SIZE];
  char		*newstr;
  size_t	size;

  newstr = xmalloc(sizeof(char));
  newstr[0] = 0;
  while ((size = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
    newstr = re_alloc(newstr, buf[0]);
  if (size == 0)
    return (NULL);
  return (newstr);
}
