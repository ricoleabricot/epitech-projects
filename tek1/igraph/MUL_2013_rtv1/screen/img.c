/*
** img.c for rvt1 in /home/gicque_p/local/igraph/MUL_2013_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 14 09:12:12 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:35:42 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

int		my_pixel_put_to_image(t_rt *rt, int x, int y, int color)
{
  int		pixel;

  pixel = x * rt->nb->bpp / 8 + y * rt->nb->sizeline;
  if (rt->nb->bpp == 0 || rt->nb->sizeline == 0)
    my_error("Error 110: Bits per pixel or Sizeline null", 110);
  rt->ptr->data[pixel] = color & 0xFF;
  rt->ptr->data[pixel + 1] = (color >> 8) & 0xFF;
  rt->ptr->data[pixel + 2] = (color >> 16) & 0xFF;
  rt->ptr->data[pixel + 3] = 0x00;
  return (0);
}

void		init_mlx(t_ptr *ptr, t_nb *nb)
{
  if ((ptr->mlx_ptr = mlx_init()) == NULL)
    my_error("Error 2: Environment disabled. End of programm", 2);
  ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH);
  ptr->data = mlx_get_data_addr                                 \
    (ptr->img_ptr, &(nb->bpp), &(nb->sizeline), &(nb->endian));
  ptr->win_ptr = mlx_new_window                         \
    (ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "Alex a bouffe mon Rt Version1");
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}
