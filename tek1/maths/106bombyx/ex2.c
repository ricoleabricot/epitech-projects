/*
** ex2.c for bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Feb 15 11:58:50 2014 Pierrick Gicquelais
** Last update Wed Feb 19 19:49:40 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void		courbe_ex2(t_ptr *ptr, t_nb *nb, double i_min, double i_max)
{
  double	y;
  double	k;
  int		xt;
  int		yt;
  int		i;
  int		tonbouy;

  k = 1;
  i = 1;
  y = 10;
  while (k <= 4)
    {
      while (i <= i_max)
	{
	  while (i < i_min)
	    {
	      y = (k * y) * ((1000 - y) / 1000);
	      i++;
	    }
	  tonbouy = (int)(y);
	  xt = nb->xo + (k * (WIN_LENGHT / 3.04) - (WIN_LENGHT / 3.1));
	  yt = (WIN_WIDTH - tonbouy) - 30;
	  if (xt > 0 && xt < WIN_LENGHT)
	    my_put_pixel_to_image(nb, ptr->data, xt, yt, 0x00FF00);
	  y = (k * y) * ((1000 - y) / 1000);
	  i++;
	}
      k = k + 0.01;
      i = 1;
    }
}

void		repere_ex2(t_ptr *ptr, t_nb *nb)
{
  int		i;
  int		j;

  for (i = -10; nb->xo + i < WIN_LENGHT - 50; i++)
    my_put_pixel_to_image(nb, ptr->data, nb->xo + i, nb->yo, 0xFF0000); // Abscisses

  for (i = -WIN_WIDTH + 30; nb->yo + i < WIN_WIDTH - 50; i++)
    my_put_pixel_to_image(nb, ptr->data, nb->xo, nb->yo + i, 0xFF0000); // Ordonnées

  for (j = 0; j <= WIN_LENGHT / 100; j += 3)
    for (i = -10; i <= 10; i++)
      my_put_pixel_to_image(nb, ptr->data, nb->xo + 100.7 * j, nb->yo + i, 0xFF0000); // Repère abscisses

  for (j = 0; j <= WIN_WIDTH / 100; j += 2)
    for (i = -10; i <= 10; i++)
      my_put_pixel_to_image(nb, ptr->data, nb->xo + i, nb->yo - 97 * j, 0xFF0000); // Repère ordonnée
}

void		fill_ex2(t_bomb *bomb, char *str, char *str2)
{
  double	k1;
  double	k2;

  k1 = atof(str);
  k2 = atof(str2);
  check_ex2(k1, k2);
  bomb->nb->flag = 2;
  repere_ex2(bomb->ptr, bomb->nb);
  courbe_ex2(bomb->ptr, bomb->nb, k1, k2);
  mlx_clear_window(bomb->ptr->mlx_ptr, bomb->ptr->win_ptr);
  mlx_put_image_to_window(bomb->ptr->mlx_ptr, bomb->ptr->win_ptr, bomb->ptr->img_ptr, 0, 0);
}
