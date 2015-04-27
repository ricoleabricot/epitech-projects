/*
** value.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 10:22:22 2014 Pierrick Gicquelais
** Last update Wed May 14 18:42:02 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

t_tmp		*stock_val(t_tmp *tmp, char *att, char *val, int cmp)
{
  if (!my_strcmp(att, X))
    tmp->x = my_getnbr(val);
  else if (!my_strcmp(att, Y))
    tmp->y = my_getnbr(val);
  else if (!my_strcmp(att, Z))
    tmp->z = my_getnbr(val);
  else if (!my_strcmp(att, ROT_X))
    tmp->rot_x = my_getnbr(val);
  else if (!my_strcmp(att, ROT_Y))
    tmp->rot_y = my_getnbr(val);
  else if (!my_strcmp(att, ROT_Z))
    tmp->rot_z = my_getnbr(val);
  else if (!my_strcmp(att, ANGLE))
    tmp->angle = my_getnbr(val);
  else if (!my_strcmp(att, COLOR))
    tmp->color = my_getnbr(val);
  else
    {
      my_fprintf(2, "Syntax error at line: %d", cmp);
      my_error("");
    }
  return (tmp);
}

void		check_val(char *val, int cmp)
{
  if (my_isnum(val))
    {
      my_fprintf(2, "Syntax error at line: %d", cmp);
      my_error("");
    }
}

int		get_val(char *s)
{
  int		i;

  i = 0;
  while (s[i] && s[i] != ' ' && s[i] != '\t')
    i++;
  if (s[i])
    i++;
  return (i);
}
