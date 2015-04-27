/*
** swrite.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:01:13 2015 Pierrick Gicquelais
** Last update Wed Mar 25 18:37:25 2015 Pierrick Gicquelais
*/

#include	"swrite.h"
#include	"merror.h"

void		swrite(int fd, char *str)
{
  if (str != NULL)
    if ((write(fd, str, strlen(str))) == -1)
      merror("Write Error");
}
