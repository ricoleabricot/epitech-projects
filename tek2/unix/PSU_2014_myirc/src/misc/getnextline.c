/*
** getnextline.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:59:42 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:59:42 2015 Pierrick Gicquelais
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
