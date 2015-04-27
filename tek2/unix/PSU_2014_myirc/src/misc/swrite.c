/*
** swrite.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:01 2015 Pierrick Gicquelais
** Last update Sat Apr  4 19:18:00 2015 Pierrick Gicquelais
*/

#include	"swrite.h"
#include	"merror.h"

int		swrite(int fd, char *str)
{
  int		ret;

  ret = 0;
  if (str != NULL)
    if ((ret = write(fd, str, strlen(str))) == -1)
      merror("Write Error");
  return (ret);
}
