/*
** sphere.c for rt in /home/gicque_p/local/igraph/MUL_2013_rtracer/src/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 14 18:50:00 2014 Pierrick Gicquelais
** Last update Wed May 14 18:50:45 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

t_obj		*my_sphere(t_obj *obj, int fd, int *cmp)
{
  t_tmp		*tmp;
  char		*s;

  tmp = new_tmp();
  tmp->name = "sphere";
  while ((s = get_next_line(fd)) && my_strcmp(s, "</SPHERE>"))
    {
      if (s[0] && s[0] != COMMENT_CHAR)
	tmp = parse_str(tmp, s, cmp);
      (*cmp)++;
      free(s);
    }
  obj = append_obj(obj, tmp);
  free(s);
  free(tmp);
  return (obj);
}
