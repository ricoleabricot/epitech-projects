/*
** merror.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:47:42 2015 Pierrick Gicquelais
** Last update Thu Jun 18 09:55:56 2015 Pierrick Gicquelais
*/

#include	"server/merror.h"

void		merror(char *str)
{
  perror(str);
  exit(EXIT_FAILURE);
}
