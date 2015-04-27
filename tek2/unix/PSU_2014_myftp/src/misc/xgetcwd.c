/*
** xgetcwd.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 11:45:24 2015 Pierrick Gicquelais
** Last update Tue Mar 17 14:13:17 2015 Pierrick Gicquelais
*/

#include	"xgetcwd.h"
#include	"merror.h"

static long	xpathconf(const char *path, int name)
{
  long		size;

  if ((size = pathconf(path, name)) == -1)
    merror("Pathconf Error");
  return (size);
}

char		*xgetcwd(const char *path, char *buf)
{
  size_t	size;

  size = xpathconf(path, _PC_PATH_MAX);
  if ((buf = getcwd(buf, size)) == NULL)
    merror("Getcwd Error");
  return (buf);
}
