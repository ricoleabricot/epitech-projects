/*
** my_first_env.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:56:34 2014 Pierrick Gicquelais
** Last update Mon May 12 15:03:23 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"parsing.h"

t_obj		*first_obj(t_obj *obj)
{
  if (obj != NULL)
    while (obj->prev != NULL)
      obj = obj->prev;
  return (obj);
}

t_obj		*last_obj(t_obj *obj)
{
  if (obj != NULL)
    while (obj->next != NULL)
      obj = obj->next;
  return (obj);
}
