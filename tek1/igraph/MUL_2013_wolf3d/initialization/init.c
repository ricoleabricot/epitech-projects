/*
** init.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jan 10 00:56:46 2014 Pierrick Gicquelais
** Last update Tue Feb  4 15:34:59 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

void		init_first_var(t_wolf *wolf)
{
  wolf->numb->speed = 0.04;
  wolf->numb->pos_x = 3.500;
  wolf->numb->pos_y = 1.500;
  wolf->numb->dir_x = 1;
  wolf->numb->dir_y = 0;
  wolf->numb->plan_u = 0;
  wolf->numb->plan_v = 0.70;
  wolf->move->move_right = 0;
  wolf->move->move_left = 0;
  wolf->move->move_up = 0;
  wolf->move->move_down = 0;
  wolf->move->move_end = 0;
}

void		init_mlx(t_wolf *wolf)
{
  if ((wolf->ptr->mlx_ptr = mlx_init()) == NULL)
    my_error("Environment is disabled. End of programm");
  wolf->ptr->img_ptr = mlx_new_image                    \
    (wolf->ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH);
  wolf->ptr->data = mlx_get_data_addr                                   \
    (wolf->ptr->img_ptr, &(wolf->numb->bpp)                             \
     , &(wolf->numb->sizeline), &(wolf->numb->endian));
  wolf->ptr->win_ptr = mlx_new_window                                   \
    (wolf->ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "Alex a boufe mon Wolf3D");
  mlx_put_image_to_window                                               \
    (wolf->ptr->mlx_ptr, wolf->ptr->win_ptr, wolf->ptr->img_ptr, 0, 0);
}

void		my_init(t_wolf *wolf)
{
  wolf->ptr = init_ptr(wolf);
  wolf->numb = init_numb(wolf);
  wolf->color = init_color(wolf);
  wolf->algo = init_algo(wolf);
  wolf->move = init_move(wolf);
  init_mlx(wolf);
  init_first_var(wolf);
}
