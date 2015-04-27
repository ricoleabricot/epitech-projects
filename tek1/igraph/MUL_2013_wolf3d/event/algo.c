/*
** algo.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jan  7 18:03:28 2014 Pierrick Gicquelais
** Last update Sun Jan 12 22:17:32 2014 Pierrick Gicquelais
*/

#include	<math.h>
#include	"../include/wolf.h"

void		init_var(t_algo *algo, t_numb *numb)
{
  algo->screen = 2 * numb->x / (double)(WIN_LENGHT) -1;
  algo->ray_x = numb->dir_x + numb->plan_u * algo->screen;
  algo->ray_y = numb->dir_y + numb->plan_v * algo->screen;
  algo->map_x = (int)(numb->pos_x);
  algo->map_y = (int)(numb->pos_y);
  algo->delta_x =							\
    sqrt(1 + pow(algo->ray_y, 2) / pow(algo->ray_x, 2));
  algo->delta_y =							\
    sqrt(1 + pow(algo->ray_x, 2) / pow(algo->ray_y, 2));
}

void		direction_choice(t_algo *algo, t_numb *numb)
{
  if (algo->ray_x < 0)
    {
      algo->step_x = -1;
      algo->dist_x = (numb->pos_x - algo->map_x) * algo->delta_x;
    }
  else
    {
      algo->step_x = 1;
      algo->dist_x = (algo->map_x + 1.0 - numb->pos_x) * algo->delta_x;
    }
  if (algo->ray_y < 0)
    {
      algo->step_y = -1;
      algo->dist_y = (numb->pos_y - algo->map_y) * algo->delta_y;
    }
  else
    {
      algo->step_y = 1;
      algo->dist_y = (algo->map_y + 1.0 - numb->pos_y) * algo->delta_y;
    }
}

void		possible_move(t_ptr *ptr, t_algo *algo)
{
  int		hit;

  hit = 0;
  while (hit == 0)
    {
      if (algo->dist_x < algo->dist_y)
  	{
  	  algo->dist_x += algo->delta_x;
  	  algo->map_x += algo->step_x;
	  algo->side = 0;
	  algo->side_color = 0;
  	}
      else
  	{
  	  algo->dist_y += algo->delta_y;
  	  algo->map_y += algo->step_y;
	  algo->side = 1;
	  algo->side_color = 1;
  	}
      if (ptr->map[algo->map_x][algo->map_y] != '0')
	hit = 1;
    }
}

double		algo_raycasting(t_ptr *ptr, t_algo *algo, t_numb *numb)
{
  double	k;

  init_var(algo, numb);
  direction_choice(algo, numb);
  possible_move(ptr, algo);
  if (ptr->map[algo->map_x][algo->map_y] == '2')
    algo->side_color = 2;
  else if (ptr->map[algo->map_x][algo->map_y] == '3')
    algo->side_color = 3;
  if (ptr->map[(int)numb->pos_x][(int)numb->pos_y] == '2')
    orange_tp(ptr, numb);
  else if (ptr->map[(int)numb->pos_x][(int)numb->pos_y] == '3')
    blue_tp(ptr, numb);
  if (algo->side == 0)
    k = fabs((algo->map_x - numb->pos_x + (1 - algo->step_x) / 2)	\
	     / algo->ray_x);
  else
    k = fabs((algo->map_y - numb->pos_y + (1 - algo->step_y) / 2)	\
	     / algo->ray_y);
  return (k);
}
