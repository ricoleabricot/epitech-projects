/*
** check.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 14 15:16:00 2014 Pierrick Gicquelais
** Last update Wed May 14 15:18:27 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

void		check_eye(t_obj *obj)
{
  int		flag;

  flag = 0;
  obj = first_obj(obj);
  while (obj)
    {
      if (!(my_strcmp(obj->name, "eye")))
	flag++;
      obj = obj->next;
    }
  if (flag < 1)
    my_error("You must enter an eye");
  if (flag > 1)
    my_error("You can't enter must than one eye");
}
