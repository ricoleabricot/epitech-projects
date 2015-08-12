/*
** swrite.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 09:48:58 2015 Pierrick Gicquelais
** Last update Fri Jul  3 10:08:09 2015 Pierrick Gicquelais
*/

#include	"server/swrite.h"

int		swrite(int fd, char *s)
{
  return (write(fd, s, strlen(s)));
}
