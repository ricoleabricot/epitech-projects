/*
** color.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jan 10 01:14:32 2014 Pierrick Gicquelais
** Last update Sun Jan 12 23:31:23 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

void		change_color(t_color *color, int blue, int green, int red)
{
  color->blue_pixel = blue;
  color->green_pixel = green;
  color->red_pixel = red;
}

void		my_color(t_color *color, t_algo *algo, int wall, double y)
{
  if (y <= -wall / 2 + WIN_WIDTH / 2)
    change_color(color, 85 + y / 4, 85 + y / 4, 0);
  else if (y >= -wall / 2 + WIN_WIDTH / 2 &&                            \
           y <= wall / 2 + WIN_WIDTH / 2 - 1 && algo->side_color == 0)
    change_color(color, 165, 165, 165);
  else if (y >= -wall / 2 + WIN_WIDTH / 2 &&                            \
           y <= wall / 2 + WIN_WIDTH / 2 - 1 && algo->side_color == 1)
    change_color(color, 128, 128, 128);
  else if (y >= -wall / 2 + WIN_WIDTH / 2 &&                            \
           y <= wall / 2 + WIN_WIDTH / 2 - 1 && algo->side_color == 2)
    change_color(color, 0, 102, 255);
  else if (y >= -wall / 2 + WIN_WIDTH / 2 &&                            \
           y <= wall / 2 + WIN_WIDTH / 2 - 1 && algo->side_color == 3)
    change_color(color, 255, 102, 0);
  else
    change_color(color, 40, 140 + y / 3, 40);
}

void		my_minimap_color(t_wolf *wolf, t_numb *numb, t_color *color)
{
  if (numb->x % 40 == 0 || numb->y % 40 == 0)
    change_color(color, 255, 255, 255);
  else if (numb->x > WIN_LENGHT - 160 && numb->x < WIN_LENGHT		\
	   - 120 && numb->y > WIN_WIDTH - 160 && numb->y < WIN_WIDTH - 120)
    change_color(color, 0, 0, 255);
  else
    change_color(color, 90, 90, 90);
  my_wall_minimap(wolf->ptr, numb, color);
  my_next_wall_minimap(wolf->ptr, numb, color);
}
