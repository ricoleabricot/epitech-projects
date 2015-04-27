/*
** my_aff_env.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:54:46 2014 Pierrick Gicquelais
** Last update Wed May 14 18:48:09 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

void		aff_obj(t_obj *obj)
{
  if (obj != NULL)
    {
      my_fprintf(1, "L'OBJET EST: %s\n", obj->name);
      my_fprintf(1, "Coordonnées: %d, %d, %d\n", obj->x, obj->y, obj->z);
      my_fprintf(1, "Rot: %d, %d, %d\n", obj->rot_x, obj->rot_y, obj->rot_z);
      my_fprintf(1, "Angle: %d et Color: %d\n\n", obj->angle, obj->color);
    }
}

void		aff_all_obj(t_obj *obj)
{
  obj = first_obj(obj);
  while (obj != NULL)
    {
      aff_obj(obj);
      obj = obj->next;
    }
}
