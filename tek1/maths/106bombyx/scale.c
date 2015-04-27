/*
** scale.c for bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Feb 15 11:00:39 2014 Pierrick Gicquelais
** Last update Wed Feb 19 19:08:39 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void		my_first_scale(t_ptr *ptr, t_nb *nb)
{
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 17, nb->yo + 17, 0xFFFFFF, "0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 2, nb->yo + 25, 0xFFFFFF, "20");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 4, nb->yo + 25, 0xFFFFFF, "40");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 6, nb->yo + 25, 0xFFFFFF, "60");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 8, nb->yo + 25, 0xFFFFFF, "80");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 10, nb->yo + 25, 0xFFFFFF, "100");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 12, nb->yo + 25, 0xFFFFFF, "120");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 14, nb->yo + 25, 0xFFFFFF, "140");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 16, nb->yo + 25, 0xFFFFFF, "160");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 89 * 18, nb->yo + 25, 0xFFFFFF, "180");
}

void		my_second_scale(t_ptr *ptr, t_nb *nb)
{
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 17, nb->yo + 17, 0xFFFFFF, "0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 1, 0xFFFFFF, "100");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 2, 0xFFFFFF, "200");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 3, 0xFFFFFF, "300");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 4, 0xFFFFFF, "400");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 5, 0xFFFFFF, "500");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 6, 0xFFFFFF, "600");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 7, 0xFFFFFF, "700");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 8, 0xFFFFFF, "800");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 9, 0xFFFFFF, "900");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 10, 0xFFFFFF, "1000");
}

void		my_third_scale(t_ptr *ptr, t_nb *nb)
{
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 17, nb->yo + 25, 0xFFFFFF, "1.0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 2, nb->yo + 25, 0xFFFFFF, "1.5");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 4, nb->yo + 25, 0xFFFFFF, "2.0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 6, nb->yo + 25, 0xFFFFFF, "2.5");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 8, nb->yo + 25, 0xFFFFFF, "3.0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 10, nb->yo + 25, 0xFFFFFF, "3.5");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo + 149 * 12, nb->yo + 25, 0xFFFFFF, "4.0");
}

void		my_fourth_scale(t_ptr *ptr, t_nb *nb)
{
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 17, nb->yo + 15, 0xFFFFFF, "0");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 2, 0xFFFFFF, "200");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 4, 0xFFFFFF, "400");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 6, 0xFFFFFF, "600");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 8, 0xFFFFFF, "800");
  mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, nb->xo - 35, nb->yo - 96 * 10, 0xFFFFFF, "1000");
}
