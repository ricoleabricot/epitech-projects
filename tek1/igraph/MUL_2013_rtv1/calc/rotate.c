/*
** rotate.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 21 10:49:39 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:38:02 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

t_vec		*rotate_x(t_vec *vec, double angle)
{
  double	m[3][3];
  double	save_vx;
  double	save_vy;

  save_vx = vec->vx;
  save_vy = vec->vy;
  angle = (angle * M_PI) / 180;
  m[0][0] = 1;
  m[0][1] = 0;
  m[0][2] = 0;
  m[1][0] = 0;
  m[1][1] = cos(angle);
  m[1][2] = -sin(angle);
  m[2][0] = 0;
  m[2][1] = sin(angle);
  m[2][2] = cos(angle);
  vec->vx = m[0][0] * save_vx + m[0][1] * save_vy + m[0][2] * vec->vz;
  vec->vy = m[1][0] * save_vx + m[1][1] * save_vy + m[1][2] * vec->vz;
  vec->vz = m[2][0] * save_vx + m[2][1] * save_vy + m[2][2] * vec->vz;
  return (vec);
}

t_vec		*rotate_y(t_vec *vec, double angle)
{
  double	m[3][3];
  double	save_vx;
  double	save_vy;

  save_vx = vec->vx;
  save_vy = vec->vy;
  angle = (angle * M_PI) / 180;
  m[0][0] = cos(angle);
  m[0][1] = 0;
  m[0][2] = sin(angle);
  m[1][0] = 0;
  m[1][1] = 1;
  m[1][2] = 0;
  m[2][0] = -sin(angle);
  m[2][1] = 0;
  m[2][2] = cos(angle);
  vec->vx = m[0][0] * save_vx + m[0][1] * save_vy + m[0][2] * vec->vz;
  vec->vy = m[1][0] * save_vx + m[1][1] * save_vy + m[1][2] * vec->vz;
  vec->vz = m[2][0] * save_vx + m[2][1] * save_vy + m[2][2] * vec->vz;
  return (vec);
}

t_vec		*rotate_z(t_vec *vec, double angle)
{
  double	m[3][3];
  double	save_vx;
  double	save_vy;

  save_vx = vec->vx;
  save_vy = vec->vy;
  angle = (angle * M_PI) / 180;
  m[0][0] = cos(angle);
  m[0][1] = -sin(angle);
  m[0][2] = 0;
  m[1][0] = sin(angle);
  m[1][1] = cos(angle);
  m[1][2] = 0;
  m[2][0] = 0;
  m[2][1] = 0;
  m[2][2] = 1;
  vec->vx = m[0][0] * save_vx + m[0][1] * save_vy + m[0][2] * vec->vz;
  vec->vy = m[1][0] * save_vx + m[1][1] * save_vy + m[1][2] * vec->vz;
  vec->vz = m[2][0] * save_vx + m[2][1] * save_vy + m[2][2] * vec->vz;
  return (vec);
}
