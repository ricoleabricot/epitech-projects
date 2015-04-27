/*
** display.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 18:08:42 2014 Pierrick Gicquelais
** Last update Sat Feb 15 10:53:48 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

int             my_put_pixel_to_image(t_nb *nb, char *data, int x, int y, int color)
{
  int           pixel;

  if (nb->bpp == 0 || nb->sizeline == 0)
    my_error("Error 145: Bits per pixel or sizeline null", 145);
  pixel = x * nb->bpp / 8 + y * nb->sizeline;
  data[pixel] = color & 0xFF;
  data[pixel + 1] = (color >> 8) & 0xFF;
  data[pixel + 2] = (color >> 16) & 0xFF;
  data[pixel + 3] = 0xFF;
  return (0);
}
