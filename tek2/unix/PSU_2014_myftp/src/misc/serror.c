/*
** serror.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 14:25:57 2015 Pierrick Gicquelais
** Last update Tue Mar 17 14:26:17 2015 Pierrick Gicquelais
*/

#include	"serror.h"

void		serror(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}
