/*
** calc.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Feb 10 13:03:58 2014 Pierrick Gicquelais
** Last update Wed Feb 19 19:49:27 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void            courbe_ex1(t_bomb *bomb, t_nb *nb, double k)
{
  int		i;
  double	x1;
  double	x2;
  int		xe;
  int		ye;
  int		save_xe;
  int		save_ye;

  x1 = 10;
  xe = nb->xo;
  ye = nb->yo - 10;
  for (i = 0; i < 1920; i++)
    {
      if (i % 10 == 0)
	{
	  x2 = k * x1 * ((1000 - x1) / 1000);
	  save_xe = xe;
	  save_ye = ye;
	  xe = nb->xo + (int)i;
	  ye = nb->yo - (int)x1 / 1.07;
	  if (xe != save_xe && ye != save_ye)
	    my_draw(bomb, save_xe, save_ye, xe, ye); // Put draw line here babe
	  x1 = x2;
	}
    }
}

void            repere_ex1(t_ptr *ptr, t_nb *nb)
{
  int           i;
  int		j;

  for (i = -10; nb->xo + i < WIN_LENGHT - 50; i++)
    my_put_pixel_to_image(nb, ptr->data, nb->xo + i, nb->yo, 0xFF0000); // Abscisses

  for (i = -WIN_WIDTH + 30; nb->yo + i < WIN_WIDTH - 50; i++)
    my_put_pixel_to_image(nb, ptr->data, nb->xo, nb->yo + i, 0xFF0000); // Ordonnées

  for (j = 0; j <= WIN_LENGHT / 100; j += 2)
    for (i = -10; i <= 10; i++)
      my_put_pixel_to_image(nb, ptr->data, nb->xo + 90 * j, nb->yo + i, 0xFF0000); // Repère abscisses

  for (j = 0; j <= WIN_WIDTH / 100; j++)
    for (i = -10; i <= 10; i++)
      my_put_pixel_to_image(nb, ptr->data, nb->xo + i, nb->yo - 97 * j, 0xFF0000); // Repère ordonnée

}

void            fill_ex1(t_bomb *bomb, char *str)
{
  double	k;

  k = atof(str);
  check_ex1(k);
  bomb->nb->flag = 1;
  repere_ex1(bomb->ptr, bomb->nb);
  courbe_ex1(bomb, bomb->nb, k);
  mlx_clear_window(bomb->ptr->mlx_ptr, bomb->ptr->win_ptr);
  mlx_put_image_to_window(bomb->ptr->mlx_ptr, bomb->ptr->win_ptr, bomb->ptr->img_ptr, 0, 0);
  my_first_scale(bomb->ptr, bomb->nb);
  my_second_scale(bomb->ptr, bomb->nb);
}
