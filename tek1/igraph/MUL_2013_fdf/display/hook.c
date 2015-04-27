/*
** hook.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  1 18:22:18 2013 Pierrick Gicquelais
** Last update Sun Dec  8 16:54:32 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

int	gere_key(int keycode, t_list *elem)
{
  if (keycode == 65307)
    my_error("End of Programm (Echap Key)");
  if (keycode == 65293)
    elem->z--;
  if (keycode == 65362)
    elem->z++;
  return (0);
}

int	gere_expose(t_ptr *ptr)
{
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  return (0);
}

void	my_hook(t_ptr *ptr, t_list **list)
{
  mlx_key_hook(ptr->win_ptr, gere_key, list);
  mlx_expose_hook(ptr->win_ptr, gere_expose, ptr);
  mlx_loop(ptr->mlx_ptr);
}
