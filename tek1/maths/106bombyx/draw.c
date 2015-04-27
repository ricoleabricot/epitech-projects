/*
** img.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  1 18:31:08 2013 Pierrick Gicquelais
** Last update Wed Feb 19 19:10:20 2014 Pierrick Gicquelais
*/

#include "bombyx.h"

void            draw_case_one(t_bomb *bomb, int x1, int y1, int x2, int y2)
{
  int           x;
  int           y;
  int           max;

  if (x1 < x2)
    {
      x = x1;
      max = x2;
    }
  else
    {
      x = x2;
      max = x1;
    }
  while (x++ <= max)
    {
      y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
      if (x > 0 && x < WIN_LENGHT && y > 0 && y < WIN_WIDTH)
	my_put_pixel_to_image(bomb->nb, bomb->ptr->data, x, y, 0x00FF00);
    }
}

void            draw_case_two(t_bomb *bomb, int x1, int y1, int x2, int y2)
{
  int           y;
  int           max;
  int           x;

  if (y1 < y2)
    {
      y = y1;
      max = y2;
    }
  else
    {
      y = y2;
      max = y1;
    }
  while (y++ <= max)
    {
      x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
      if (x > 0 && x < WIN_LENGHT && y > 0 && y < WIN_WIDTH)
	my_put_pixel_to_image(bomb->nb, bomb->ptr->data, x, y, 0x00FF00);
    }
}

void            draw_case_verti(t_bomb *bomb, int x1, int y1, int x2, int y2)
{
  int           y;
  int           max;

  x1 = x2;
  if (y1 <= y2)
    {
      y = y1;
      max = y2;
    }
  else
    {
      y = y2;
      max = y1;
    }
  while (y++ <= max)
    {
      if (x1 > 0 && x1 < WIN_LENGHT && y > 0 && y < WIN_WIDTH)
	my_put_pixel_to_image(bomb->nb, bomb->ptr->data, x1, y, 0x00FF00);
    }
}

void            draw_case_hori(t_bomb *bomb, int x1, int y1, int x2, int y2)
{
  int           x;
  int           max;

  y1 = y2;
  if (x1 <= x2)
    {
      x = x1;
      max = x2;
    }
  else
    {
      x = x2;
      max = x1;
    }
  while (x++ <= max)
    {
      if (x > 0 && x < WIN_LENGHT && y1 > 0 && y1 < WIN_WIDTH)
	my_put_pixel_to_image(bomb->nb, bomb->ptr->data, x, y1, 0x00FF00);
    }
}

void            my_draw(t_bomb *bomb, int x1, int y1, int x2, int y2)
{
  if (abs(x2 - x1) > abs(y2 - y1))
    draw_case_one(bomb, x1, y1, x2, y2);
  else
    draw_case_two(bomb, x1, y1, x2, y2);
  if (x1 == x2)
    draw_case_verti(bomb, x1, y1, x2, y2);
  else if (y1 == y2)
    draw_case_hori(bomb, x1, y1, x2, y2);
}
