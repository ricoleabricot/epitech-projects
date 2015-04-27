/*
** error.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 10:28:11 2015 Pierrick Gicquelais
** Last update Mon Mar 16 16:42:01 2015 Pierrick Gicquelais
*/

#include	"merror.h"

void		merror(char *str)
{
  perror(str);
  exit(errno);
}
