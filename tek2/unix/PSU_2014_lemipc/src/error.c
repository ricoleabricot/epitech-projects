/*
** error.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 20:18:29 2015 Pierrick Gicquelais
** Last update Fri Feb 27 20:37:29 2015 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<errno.h>

#include	"error.h"

void		my_error(const char *content)
{
  perror(content);
  exit(EXIT_FAILURE);
}
