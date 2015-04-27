/*
** move.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jan  9 13:31:21 2014 Pierrick Gicquelais
** Last update Fri Jan 10 10:01:51 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

int		move_on(int keycode, t_wolf *wolf)
{
  if (keycode == ARROW_RIGHT)
    wolf->move->move_right = 1;
  if (keycode == ARROW_LEFT)
    wolf->move->move_left = 1;
  if (keycode == ARROW_UP)
    wolf->move->move_up = 1;
  if (keycode == ARROW_DOWN)
    wolf->move->move_down = 1;
  if (keycode == SHIFT_KEY)
    wolf->numb->speed += 0.05;
  if (keycode == CTRL_KEY)
    wolf->numb->speed -= 0.03;
  if (keycode == END_KEY)
    wolf->move->move_end = 1;
  return (0);
}

int		move_off(int keycode, t_wolf *wolf)
{
  if (keycode == ARROW_RIGHT)
    wolf->move->move_right = 0;
  if (keycode == ARROW_LEFT)
    wolf->move->move_left = 0;
  if (keycode == ARROW_UP)
    wolf->move->move_up = 0;
  if (keycode == ARROW_DOWN)
    wolf->move->move_down = 0;
  if (keycode == SHIFT_KEY)
    wolf->numb->speed = 0.04;
  if (keycode == CTRL_KEY)
    wolf->numb->speed = 0.04;
  if (keycode == END_KEY)
    wolf->move->move_end = 0;
  return (0);
}

int		move_end(t_wolf *wolf)
{
  int	i;

  i = -1;
  mlx_clear_window(wolf->ptr->mlx_ptr, wolf->ptr->win_ptr);
  mlx_destroy_window(wolf->ptr->mlx_ptr, wolf->ptr->win_ptr);
  while (wolf->ptr->map[++i])
    free(wolf->ptr->map[i]);
  free(wolf->ptr->map);
  free(wolf->ptr);
  free(wolf->numb);
  free(wolf->color);
  free(wolf->algo);
  free(wolf->move);
  free(wolf);
  my_error("End of Programm (Echap Key)");
  return (0);
}
