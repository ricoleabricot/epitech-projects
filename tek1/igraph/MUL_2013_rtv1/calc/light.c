/*
** light.c for rtv1 in /home/gicque_p/local/igraph/MUL_2013_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Feb 27 16:50:06 2014 Pierrick Gicquelais
** Last update Fri Mar 14 14:53:51 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

static int	my_rgb(int r, int g, int b)
{
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  return (b * 256 * 256 + g * 256 + r);
}

int             my_lum(t_vec *v, int color)
{
  double        scalaire;
  double        normal;
  double        normal_lum;
  double        cosa;
  int           new_color;

  scalaire = (v->px * v->lx) + (v->py * v->ly) + (v->pz * v->lz);
  normal = sqrt(pow(v->px, 2) + pow(v->py, 2) + pow(v->pz, 2));
  normal_lum = sqrt(pow(v->lx, 2) + pow(v->ly, 2) + pow(v->lz, 2));
  cosa = (scalaire / (normal * normal_lum));
  cosa = 1 - cosa;
  if (cosa <= 0)
    return (0);
  color = color * (1 - BRILLANCE) + COL_SPOT * BRILLANCE;
  new_color = my_rgb(cosa * (color & 0xFF), cosa *			\
  		     ((color >> 8) & 0xFF), cosa * ((color >> 16) & 0xFF));
  return (new_color);
}

void		vec_lum(t_nb *n, t_vec *v)
{
  v->px = XOEIL + n->k * v->vx;
  v->py = YOEIL + n->k * v->vy;
  v->pz = ZOEIL + n->k * v->vz;
  v->lx = v->px - XLUM;
  v->ly = v->py - YLUM;
  v->lz = v->pz - ZLUM;
  v->sx = v->px + n->k * v->lx;
  v->sy = v->py + n->k * v->ly;
  v->sz = v->pz + n->k * v->lz;
}
