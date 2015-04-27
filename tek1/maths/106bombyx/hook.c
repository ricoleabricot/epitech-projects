/*
** hook.c for bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 11:27:15 2014 Pierrick Gicquelais
** Last update Wed Feb 19 18:45:14 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

int             gere_key(int keycode, t_bomb *bomb)
{
  if (keycode == END_KEY)
    my_free(bomb);
  return (0);
}

int             gere_expose(t_bomb *bomb)
{
  mlx_put_image_to_window(bomb->ptr->mlx_ptr, bomb->ptr->win_ptr, bomb->ptr->img_ptr, 0, 0);
  if (bomb->nb->flag == 1)
    {
      my_first_scale(bomb->ptr, bomb->nb);
      my_second_scale(bomb->ptr, bomb->nb);
    }
  else
    {
      my_third_scale(bomb->ptr, bomb->nb);
      my_fourth_scale(bomb->ptr, bomb->nb);
    }
  return (0);
}

void            my_hook(t_bomb *bomb)
{
  mlx_hook(bomb->ptr->win_ptr, KeyPress, KeyRelease, &gere_key, bomb);
  mlx_expose_hook(bomb->ptr->win_ptr, &gere_expose, bomb);
  mlx_loop(bomb->ptr->mlx_ptr);
}
