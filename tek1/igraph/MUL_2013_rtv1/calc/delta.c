/*
** delta.c for rvt1 in /home/gicque_p/local/igraph/MUL_2013_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar 13 18:17:55 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:33:59 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

void		delta_sphere(t_nb *n, double delta, double a, double b)
{
  double	x1;
  double	x2;

  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  if (x1 > 0.000001 && (x1 < x2 || x2 < 0.000001) && x1 < n->k)
    {
      n->k = x1;
      n->color = COLSPHERE;
    }
  else if (x2 > 0.00001 && (x2 < x1 || x1 < 0.00001) && x2 < n->k)
    {
      n->k = x2;
      n->color = COLSPHERE;
    }
}

void		delta_cylinder(t_nb *n, double delta, double a, double b)
{
  double	x1;
  double	x2;

  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  if (x1 > 0.000001 && (x1 < x2 || x2 < 0.000001) && x1 < n->k)
    {
      n->k = x1;
      n->color = COLCYL;
    }
  else if (x2 > 0.00001 && (x2 < x1 || x1 < 0.00001) && x2 < n->k)
    {
      n->k = x2;
      n->color = COLCYL;
    }
}

void		delta_cone(t_nb *n, double delta, double a, double b)
{
  double	x1;
  double	x2;

  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  if (x1 > 0.000001 && (x1 < x2 || x2 < 0.000001) && x1 < n->k)
    {
      n->k = x1;
      n->color = COLCONE;
    }
  else if (x2 > 0.00001 && (x2 < x1 || x1 < 0.00001) && x2 < n->k)
    {
      n->k = x2;
      n->color = COLCONE;
    }
}
