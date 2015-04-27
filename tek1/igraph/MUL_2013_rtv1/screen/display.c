/*
** display.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Feb  7 10:03:17 2014 Pierrick Gicquelais
** Last update Mon Mar 17 17:39:19 2014 Pierrick Gicquelais
*/

/*
  Mettre les fonctions suivantes pour tester les ombres (non fonctionnelles)
  shadow_sphere(n, v, RSPHERE)
  shadow_plan(n, v)
  shadow_cylinder(n, v, RCYL)
  shadow_cone(n, v, RCONE)
 */

#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

static int	calc(t_nb *n, t_vec *v)
{
  n->color = 0x000000;
  n->k = 10000;
  my_inter_sphere(n, v, RSPHERE);
  v = rotate_x(v, -XANGLE * 2);
  my_inter_plan(n, v);
  v = rotate_x(v, XANGLE * 2);
  my_inter_cylinder(n, v, RCYL);
  my_inter_cone(n, v, RCONE);
  vec_lum(n, v);
  return (my_lum(v, n->color));
}

void		remplis_img(t_rt *rt)
{
  int		x;
  int		y;

  x = 0;
  while (x++ < WIN_LENGHT)
    {
      y = 0;
      while (y++ < WIN_WIDTH)
	{
	  init_oeil(rt->vec, x, y);
	  my_pixel_put_to_image(rt, x, y, calc(rt->nb, rt->vec));
	}
      if (x % (WIN_LENGHT / 10) == 0)
	{
	  my_putstr("Please wait... ");
	  my_putnbr(x / (WIN_LENGHT / 100));
	  my_putstr("%\n");
	}
    }
}
