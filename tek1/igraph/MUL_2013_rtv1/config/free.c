/*
** free.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Feb  7 14:37:23 2014 Pierrick Gicquelais
** Last update Fri Mar 14 11:32:25 2014 Pierrick Gicquelais
*/

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

void		my_free(t_rt *rt)
{
  mlx_clear_window(rt->ptr->mlx_ptr, rt->ptr->win_ptr);
  mlx_destroy_window(rt->ptr->mlx_ptr, rt->ptr->win_ptr);
  free(rt->ptr->img_ptr);
  free(rt->ptr);
  free(rt->nb);
  free(rt->vec);
  free(rt);
  my_putstr("Echap key pressed. End of programm !\n");
  exit(42);
}
