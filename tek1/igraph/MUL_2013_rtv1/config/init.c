/*
** init.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb  7 09:41:48 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:36:31 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

t_vec		*init_oeil(t_vec *vec, int x, int y)
{
  vec->vx = (WIN_WIDTH / tan((25 * M_PI) / 180));
  vec->vy = (WIN_LENGHT / 2) - x;
  vec->vz = (WIN_WIDTH / 2) - y;
  vec = rotate_x(vec, XANGLE);
  vec = rotate_y(vec, YANGLE);
  vec = rotate_x(vec, ZANGLE);
  return (vec);
}

static t_ptr	*init_ptr(t_rt *rt)
{
  if ((rt->ptr = malloc(sizeof(t_ptr))) == NULL)
    my_error("Error 3: Memory allocation", 3);
  return (rt->ptr);
}

static t_nb	*init_nb(t_rt *rt)
{
  if ((rt->nb = malloc(sizeof(t_nb))) == NULL)
    my_error("Error 4: Memory allocation", 4);
  return (rt->nb);
}

static t_vec	*init_vec(t_rt *rt)
{
  if ((rt->vec = malloc(sizeof(t_vec))) == NULL)
    my_error("Error 5: Memory allocation", 5);
  return (rt->vec);
}

void		my_init(t_rt *rt)
{
  init_ptr(rt);
  init_nb(rt);
  init_vec(rt);
  init_mlx(rt->ptr, rt->nb);
}
