/*
** rotate.c for rt in /home/gicque_p/local/igraph/MUL_2013_rtracer/src/calc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 14 16:24:11 2014 Pierrick Gicquelais
** Last update Wed May 14 16:26:54 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"calc.h"

void		rotate_x(double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

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
}

void		rotate_y(double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

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
}

void		rotate_z(double angle)
{
  double	m[3][3];
  double	save_x;
  double	save_y;

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
}
