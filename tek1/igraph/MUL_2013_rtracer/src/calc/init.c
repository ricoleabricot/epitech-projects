/*
** init.c for rt in /home/gicque_p/local/igraph/MUL_2013_rtracer/src/calc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 14 18:12:58 2014 Pierrick Gicquelais
** Last update Wed May 14 18:14:11 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"
#include	"calc.h"

t_rt		*init_rt(void)
{
  t_rt		*rt;

  if ((rt = malloc(sizeof(t_rt))) == NULL)
    my_error("Can't alloc memory");
  return (rt);
}
