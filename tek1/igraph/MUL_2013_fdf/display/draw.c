/*
** img.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  1 18:31:08 2013 Pierrick Gicquelais
** Last update Sun Dec  8 13:45:41 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

void	draw_case_one(t_dat *dat, char *data)
{
  int	x;
  int	modX;
  int	modY;
  int	max;

  if (dat->x1 < dat->x2)
    {
      x = dat->x1;
      max = dat->x2;
    }
  else
    {
      x = dat->x2;
      max = dat->x1;
    }
  while (x <= max)
    {
      modX = x;
      modY = ((dat->y1 + ((dat->y2 - dat->y1) *				\
			  (x - dat->x1) / (dat->x2 - dat->x1))));
      if (modX > 0 && modX < 1650 && modY > 0 && modY < 1000)
	my_pixel_put_to_image						\
	  (dat, data, modX *  dat->bpp / 8, modY * dat->sizeline);
      x++;
    }
}

void	draw_case_two(t_dat *dat, char *data)
{
  int	y;
  int	modX;
  int	modY;
  int	max;

  if (dat->y1 < dat->y2)
    {
      y = dat->y1;
      max = dat->y2;
    }
  else
    {
      y = dat->y2;
      max = dat->y1;
    }
  while (y <= max)
    {
      modX = y;
      modY = ((dat->x1 + ((dat->x2 - dat->x1) * \
			  (y - dat->y1) / (dat->y2 - dat->y1))));
      if (modX > 0 && modX < 1000 && modY > 0 && modY < 1650)
	my_pixel_put_to_image						\
	  (dat, data, modX * dat->sizeline, modY * dat->bpp / 8);
      y++;
    }
}

void	draw_vertical(t_dat *dat, char *data)
{
  int	y;
  int	modX;
  int	modY;
  int	max;

  if (dat->y1 < dat->y2)
    {
      y = dat->y1;
      max = dat->y2;
    }
  else
    {
      y = dat->y2;
      max = dat->y1;
    }
  while (y <= max)
    {
      modX = dat->x1;
      modY = (y * dat->sizeline + dat->x1);
      if (modX > 0 && modX < 1650 && modY > 0 && modY < 1000)
	my_pixel_put_to_image(dat, data, modX, modY * dat->bpp / 8);
      y++;
    }
}
void	draw_horizontal(t_dat *dat, char *data)
{
  int	x;
  int	modX;
  int	modY;
  int	max;

  if (dat->x1 < dat->x2)
    {
      x = dat->x1;
      max = dat->x2;
    }
  else
    {
      x = dat->x2;
      max = dat->x1;
    }
  while (x <= max)
    {
      modX = (x * dat->bpp / 8 + dat->y1);
      modY = dat->y1;
      if (modX > 0 && modX < 1650 && modY > 0 && modY < 1000)
	my_pixel_put_to_image(dat, data, modX * dat->sizeline, modY);
      x++;
    }
}

void	my_draw(t_dat *dat, char *data, t_list *point1, t_list *point2)
{
  dat->x1 = point1->X;
  dat->y1 = point1->Y;
  dat->x2 = point2->X;
  dat->y2 = point2->Y;
  if (my_abs(point2->X - point2->Y) >= my_abs(point2->Y - point2->X))
    {
      if (dat->x1 != dat->x2)
	{
	  draw_case_one(dat, data);
	  draw_case_two(dat, data);
	}
      else
	draw_horizontal(dat, data);
    }
  else
    {
      if (dat->y1 != dat->y2)
	{
	  draw_case_two(dat, data);
	  draw_case_one(dat, data);
	}
      else
	draw_vertical(dat, data);
    }
}
