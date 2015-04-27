/*
** hook.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb  7 15:35:57 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:35:16 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

static int	gere_key(int keycode, t_rt *rt)
{
  if (keycode == END_KEY)
    my_free(rt);
  return (0);
}

static int	gere_expose(t_ptr *ptr)
{
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  return (0);
}

void		my_hook(t_rt *rt)
{
  mlx_key_hook(rt->ptr->win_ptr, &gere_key, rt);
  mlx_expose_hook(rt->ptr->win_ptr, &gere_expose, rt->ptr);
  mlx_loop(rt->ptr->mlx_ptr);
}
