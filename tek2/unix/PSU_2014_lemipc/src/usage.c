/*
** usage.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 22:03:46 2015 Pierrick Gicquelais
** Last update Thu Mar  5 20:30:31 2015 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"usage.h"

void		usage(char **argv)
{
  fprintf(stderr, "%s: %s\n", argv[0], "team_name team_id");
  exit(EXIT_FAILURE);
}
