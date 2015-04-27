/*
** function.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 18:28:10 2014 Pierrick Gicquelais
** Last update Wed May 14 15:50:54 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

static	char	(*g_fct[7]) =
{
  EYE,
  SPHERE,
  CYL,
  CONE,
  PLAN,
  SPOT,
  NULL
};

static	t_obj	*(*g_ptr[7])(t_obj *, int, int *) =
{
  &my_eye,
  &my_sphere,
  &my_cyl,
  &my_cone,
  &my_plan,
  &my_spot,
  NULL
};

t_obj            *stock_choice(t_obj *obj, char *s, int fd, int *cmp)
{
  int		i;

  i = 0;
  while (g_fct[i] && my_strcmp(s, g_fct[i]))
    i++;
  if (g_ptr[i] == NULL)
    {
      my_fprintf(2, "Syntax error at line %d", *cmp);
      my_error("");
    }
  (*cmp)++;
  obj = g_ptr[i](obj, fd, cmp);
  return (obj);
}
