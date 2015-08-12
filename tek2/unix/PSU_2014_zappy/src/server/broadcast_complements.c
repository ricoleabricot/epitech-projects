/*
** broadcast_complements.c for zappy in /home/boisso_c/rendu/PSU_2014_zappy/src/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Wed Jul  1 13:10:13 2015 Christian Boisson
** Last update Thu Jul  2 12:27:11 2015 Christian Boisson
*/

#include	<math.h>
#include	"server/commands_client.h"
#include	"server/server.h"
#include	"server/broadcast.h"
#include	"server/abs.h"

void		set_virtual(double *d, double tmp_d, int *virtual, int v)
{
  (*d) = tmp_d;
  (*virtual) = v;
}

void		set_virtual_pos(int virtual, int *x, int *y, t_player *tgt)
{
  int		x_max;
  int		y_max;

  x_max = (*x);
  y_max = (*y);
  (*x) = tgt->x;
  (*y) = tgt->y;
  if (virtual == 2)
    (*y) -= y_max;
  else if (virtual == 3)
    (*x) -= x_max;
  else if (virtual == 4)
    (*y) += y_max;
  else if (virtual == 5)
    (*x) += x_max;
}

void		get_virtual_pos(t_player *src, t_player *tgt, int *x, int *y)
{
  int		x_max;
  int		y_max;
  double	d;
  double	tmp_d;
  int		virtual;

  x_max = (*x);
  y_max = (*y);
  virtual = 1;
  d = ABS(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  tmp_d = ABS(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y - y_max - tgt->y, 2)));
  if (tmp_d < d)
    set_virtual(&d, tmp_d, &virtual, 2);
  tmp_d = ABS(sqrt(pow(tgt->x - x_max - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  if (tmp_d < d)
    set_virtual(&d, tmp_d, &virtual, 3);
  tmp_d = ABS(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y + y_max - tgt->y, 2)));
  if (tmp_d < d)
    set_virtual(&d, tmp_d, &virtual, 4);
  tmp_d = ABS(sqrt(pow(tgt->x + x_max - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  if (tmp_d < d)
    set_virtual(&d, tmp_d, &virtual, 5);
   set_virtual_pos(virtual, x, y, tgt);
}

int		get_tmp_k(int xa, int ya, int xb, int yb)
{
  static int	kval[3][3] = {DIRTOK};
  int		xdir;
  int		ydir;

  xdir = 0;
  ydir = 0;
  if (xa > xb)
    xdir = 1;
  else if (xa < xb)
    xdir = 2;
  if (ya > yb)
    ydir = 1;
  else if (ya < yb)
    ydir = 2;
  return (kval[xdir][ydir]);
}

int		alter_k(int k, int orientation)
{
  int		new_k;

  if (k == 0)
    return (k);
  if (orientation == NORTH)
    new_k = k;
  else if (orientation == EAST)
    new_k = k + 2;
  else if (orientation == SOUTH)
    new_k = k + 4;
  else if (orientation == WEST)
    new_k = k + 6;
  new_k = ((new_k - 1) % 8) + 1;
  return (new_k);
}
