/*
** my_env.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:55:32 2014 Pierrick Gicquelais
** Last update Wed May 14 15:06:49 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

t_obj		*new_obj(void)
{
  t_obj		*obj;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    my_error("Can't alloc memory");
  obj->prev = NULL;
  obj->next = NULL;
  obj->name = NULL;
  obj->x = 0;
  obj->y = 0;
  obj->z = 0;
  obj->rot_x = 0;
  obj->rot_y = 0;
  obj->rot_z = 0;
  obj->angle = 0;
  obj->color = 0x000000;
  return (obj);
}
