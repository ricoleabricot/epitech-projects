/*
** hook.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec 23 12:54:51 2013 Pierrick Gicquelais
** Last update Sun Jan 12 22:33:23 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

int		gere_expose(t_ptr *ptr)
{
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  return (0);
}

int		gere_key(t_wolf *wolf)
{
  if (wolf->move->move_right == 1)
    right_rotate(wolf->numb);
  if (wolf->move->move_left == 1)
    left_rotate(wolf->numb);
  if (wolf->move->move_up == 1)
    up_deplacement(wolf->ptr, wolf->numb);
  if (wolf->move->move_down == 1)
    down_deplacement(wolf->ptr, wolf->numb);
  if (wolf->move->move_end == 1)
    move_end(wolf);
  if (!(wolf->move->move_right != 0 && wolf->move->move_left != 0 &&	\
	wolf->move->move_up != 0 && wolf->move->move_down != 0))
    {
      display_wall(wolf, wolf->numb);
      display_minimap(wolf, wolf->numb);
      mlx_put_image_to_window						\
	(wolf->ptr->mlx_ptr, wolf->ptr->win_ptr, wolf->ptr->img_ptr, 0, 0);
    }
  mlx_expose_hook(wolf->ptr->win_ptr, &gere_expose, wolf->ptr);
  return (0);
}

void		my_hook(t_wolf *wolf)
{
  mlx_hook(wolf->ptr->win_ptr, KeyPress, KeyPressMask, &move_on, wolf);
  mlx_hook(wolf->ptr->win_ptr, KeyRelease, KeyReleaseMask, &move_off, wolf);
  mlx_loop_hook(wolf->ptr->mlx_ptr, gere_key, wolf);
  mlx_loop(wolf->ptr->mlx_ptr);
}
