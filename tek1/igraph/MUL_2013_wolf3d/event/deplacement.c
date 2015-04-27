/*
** deplacement.h for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jan  8 12:55:08 2014 Pierrick Gicquelais
** Last update Sun Jan 12 16:49:35 2014 Pierrick Gicquelais
*/

#include	<math.h>
#include	"../include/wolf.h"

int 		up_deplacement(t_ptr *ptr, t_numb *numb)
{
  char		ns_wall;
  char		we_wall;

  ns_wall = ptr->map						\
    [(int)(numb->pos_x)][(int)(numb->pos_y + numb->dir_y * numb->speed)];
  we_wall = ptr->map						\
    [(int)(numb->pos_x + numb->dir_x * numb->speed)][(int)(numb->pos_y)];
  if (ns_wall == '0' || ns_wall == '2' || ns_wall == '3')
    numb->pos_y += numb->dir_y * numb->speed;
  if (we_wall == '0' || we_wall == '2' || we_wall == '3')
    numb->pos_x += numb->dir_x * numb->speed;
  return (0);
}

int 		down_deplacement(t_ptr *ptr, t_numb *numb)
{
  char		ns_wall;
  char		we_wall;

  ns_wall = ptr->map						\
    [(int)(numb->pos_x)][(int)(numb->pos_y - numb->dir_y * numb->speed)];
  we_wall = ptr->map						\
    [(int)(numb->pos_x - numb->dir_x * numb->speed)][(int)(numb->pos_y)];
  if (ns_wall == '0' || ns_wall == '2' || ns_wall == '3')
    numb->pos_y -= numb->dir_y * numb->speed;
  if (we_wall == '0' || we_wall == '2' || we_wall == '3')
    numb->pos_x -= numb->dir_x * numb->speed;
  return (0);
}

void		left_rotate(t_numb *numb)
{
  double	save_dir_x;
  double	save_plan_u;

  save_dir_x = numb->dir_x;
  save_plan_u = numb->plan_u;
  numb->plan_u =							\
    numb->plan_u * cos(-ROTATE_SPEED) - numb->plan_v * sin(-ROTATE_SPEED);
  numb->plan_v =							\
    save_plan_u * sin(-ROTATE_SPEED) + numb->plan_v * cos(-ROTATE_SPEED);
  numb->dir_x =								\
    numb->dir_x * cos(-ROTATE_SPEED) - numb->dir_y * sin(-ROTATE_SPEED);
  numb->dir_y =								\
    save_dir_x * sin(-ROTATE_SPEED) + numb->dir_y * cos(-ROTATE_SPEED);
}

void		right_rotate(t_numb *numb)
{
  double	save_dir_x;
  double	save_plan_u;

  save_dir_x = numb->dir_x;
  save_plan_u = numb->plan_u;
  numb->plan_u =							\
    numb->plan_u * cos(ROTATE_SPEED) - numb->plan_v * sin(ROTATE_SPEED);
  numb->plan_v =							\
    save_plan_u * sin(ROTATE_SPEED) + numb->plan_v * cos(ROTATE_SPEED);
  numb->dir_x =								\
    numb->dir_x * cos(ROTATE_SPEED) - numb->dir_y * sin(ROTATE_SPEED);
  numb->dir_y =								\
    save_dir_x * sin(ROTATE_SPEED) + numb->dir_y * cos(ROTATE_SPEED);
}
