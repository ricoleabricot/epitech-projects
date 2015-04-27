/*
** my_append_env.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:55:13 2014 Pierrick Gicquelais
** Last update Wed May 14 16:20:04 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"parsing.h"

t_obj		*append_obj(t_obj *old, t_tmp *tmp)
{
  t_obj		*new;

  new = new_obj();
  if ((old = last_obj(old)) != NULL)
    old->next = new;
  new->name = tmp->name;
  new->x = tmp->x;
  new->y = tmp->y;
  new->z = tmp->z;
  new->rot_x = tmp->rot_x;
  new->rot_y = tmp->rot_y;
  new->rot_z = tmp->rot_z;
  new->angle = tmp->angle;
  new->color = tmp->color;
  new->prev = old;
  new->next = NULL;
  return (new);
}
