/*
** shadow.c for rtv1 in /home/gicque_p/local/igraph/MUL_2013_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 14 11:57:27 2014 Pierrick Gicquelais
** Last update Fri Mar 14 14:54:34 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

static void	shadow_delta(t_nb *n, double delta, double a, double b)
{
  double	x1;
  double	x2;
  double	q;

  x1 = -b - sqrt(delta) / (2 * a);
  x2 = -b + sqrt(delta) / (2 * a);
  if (x1 < x2)
    q = x1;
  else
    q = x2;
  if (q > 0 && q < 1)
    {
      n->k = 0;
      n->color = 0x000000;
    }
}

void		shadow_plan(t_nb *n, t_vec *v)
{
  double	q;

  v->lz += ZPLAN;
  if (v->lz != 0)
    q = -(v->sz) / v->lz;
  if (q < n->k && q > 0.00001)
    {
      n->k = q;
      n->color = COLPLAN;
    }
  v->lz -= ZPLAN;
}

void		shadow_sphere(t_nb *n, t_vec *v, int ray)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v->lx, 2) + pow(v->ly, 2) + pow(v->lz, 2);
  b = (2 * v->sx * v->lx) + (2 * v->sy * v->ly) + (2 * ZSPHERE * v->lz);
  c = pow(v->sx, 2) + pow(v->sy, 2) + pow(ZSPHERE, 2) - pow(ray, 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    shadow_delta(n, delta, a, b);
}

void		shadow_cylinder(t_nb *n, t_vec *v, int ray)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v->lx, 2) + pow(v->ly, 2);
  b = (2 * v->sz * v->lx) + (2 * v->sy * v->ly);
  c = pow(v->sz, 2) + pow(v->sy, 2) - pow(ray, 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    shadow_delta(n, delta, a, b);
}

void		shadow_cone(t_nb *n, t_vec *v, double angle)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  angle = (angle * M_PI) / 180;
  a = pow(v->lx, 2) + pow(v->ly, 2) - (pow(v->lz, 2) / pow(tan(angle), 2));
  b = (2 * v->sx * v->lx) + (2 * v->sy * v->ly) -	\
    (2 * v->sz * v->lz / pow(tan(angle), 2));
  c = pow(v->sx, 2) + pow(v->sy, 2) - pow(v->sz, 2) / pow(tan(angle), 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    shadow_delta(n, delta, a, b);
}
