/*
** serror.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 13:58:43 2015 Pierrick Gicquelais
** Last update Thu Jun 18 14:00:01 2015 Pierrick Gicquelais
*/

#include	"server/serror.h"

void		serror(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}
