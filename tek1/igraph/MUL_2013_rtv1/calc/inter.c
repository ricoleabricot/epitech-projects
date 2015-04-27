/*
** inter2.c for rtv1 in /home/gicque_p/local/igraph/MUL_2013_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar 13 11:27:16 2014 Pierrick Gicquelais
** Last update Fri Mar 14 12:06:28 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

void		my_inter_plan(t_nb *n, t_vec *v)
{
  double	q;

  v->vz += ZPLAN;
  if (v->vz != 0)
    q = -ZOEIL / v->vz;
  if (q < n->k && q > 0.00001)
    {
      n->k = q;
      n->color = COLPLAN;
    }
  v->vz -= ZPLAN;
}

void		my_inter_sphere(t_nb *n, t_vec *v, int ray)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v->vx, 2) + pow(v->vy, 2) + pow(v->vz, 2);
  b = (2 * XSPHERE * v->vx) + (2 * YSPHERE * v->vy) + (2 * ZSPHERE * v->vz);
  c = pow(XSPHERE, 2) + pow(YSPHERE, 2) + pow(ZSPHERE, 2) - pow(ray, 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    delta_sphere(n, delta, a, b);
}

void		my_inter_cylinder(t_nb *n, t_vec *v, int ray)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v->vx, 2) + pow(v->vy, 2);
  b = (2 * XCYL * v->vx) + (2 * YCYL * v->vy);
  c = pow(XCYL, 2) + pow(YCYL, 2) - pow(ray, 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    delta_cylinder(n, delta, a, b);
}

void		my_inter_cone(t_nb *n, t_vec *v, double angle)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  angle = (angle * M_PI) / 180;
  a = pow(v->vx, 2) + pow(v->vy, 2) - (pow(v->vz, 2) / pow(tan(angle), 2));
  b = (2 * XCONE * v->vx) + (2 * YCONE * v->vy) -	\
    (2 * ZCONE * v->vz / pow(tan(angle), 2));
  c = pow(XCONE, 2) + pow(YCONE, 2) - pow(ZCONE, 2) / pow(tan(angle), 2);
  delta = b * b - 4 * a * c;
  if (delta >= 0)
    delta_cone(n, delta, a, b);
}
