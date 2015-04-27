/*
** tmp.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 14 07:54:53 2014 Pierrick Gicquelais
** Last update Wed May 14 15:07:16 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

t_tmp		*new_tmp(void)
{
  t_tmp		*tmp;

  if ((tmp = malloc(sizeof(t_tmp))) == NULL)
    my_error("Can't alloc memory");
  tmp->name = NULL;
  tmp->x = 0;
  tmp->y = 0;
  tmp->z = 0;
  tmp->rot_x = 0;
  tmp->rot_y = 0;
  tmp->rot_z = 0;
  tmp->angle = 0;
  tmp->color = 0x000000;
  return (tmp);
}
