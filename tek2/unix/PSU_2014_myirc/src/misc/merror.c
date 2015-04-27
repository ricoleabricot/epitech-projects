/*
** merror.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:59:47 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:59:48 2015 Pierrick Gicquelais
*/

#include	"merror.h"

void		merror(char *str)
{
  perror(str);
  exit(errno);
}
