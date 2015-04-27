/*
** my_free_obj.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:57:44 2014 Pierrick Gicquelais
** Last update Wed May 14 18:31:47 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"parsing.h"

void		free_obj(t_obj *obj)
{
  if (obj != NULL)
    free(obj);
}

void		free_all_obj(t_obj *obj)
{
  t_obj		*tmp;

  obj = first_obj(obj);
  while (obj)
    {
      tmp = obj;
      obj = obj->next;
      free_obj(tmp);
    }
}

void		free_str(char *s1, char *s2, char *s3)
{
  free(s1);
  free(s2);
  free(s3);
}
