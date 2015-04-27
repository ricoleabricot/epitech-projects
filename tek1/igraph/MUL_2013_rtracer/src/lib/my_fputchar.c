/*
** my_fputchar.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/lib
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:06:05 2014 Pierrick Gicquelais
** Last update Mon May 12 14:06:33 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"

int		my_fputchar(int fd, char c)
{
  return (write(fd, &c, 1));
}
