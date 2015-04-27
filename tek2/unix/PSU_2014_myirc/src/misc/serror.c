/*
** serror.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:59:52 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:59:53 2015 Pierrick Gicquelais
*/

#include	"serror.h"

void		serror(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}
