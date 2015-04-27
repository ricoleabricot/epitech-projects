/*
** minimap.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d/screen
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jan 12 23:22:12 2014 Pierrick Gicquelais
** Last update Sun Jan 12 23:30:42 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

void		my_next_wall_minimap(t_ptr *ptr, t_numb *numb, t_color *color)
{
  if (numb->x > WIN_LENGHT - 200 && numb->x < WIN_LENGHT                \
      - 160 && numb->y > WIN_WIDTH - 200 && numb->y < WIN_WIDTH - 160)
    {
      if (ptr->map[(int)(numb->pos_x - 1)][(int)(numb->pos_y - 1)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 120 && numb->x < WIN_LENGHT           \
           - 80 && numb->y > WIN_WIDTH - 200 && numb->y < WIN_WIDTH - 160)
    {
      if (ptr->map[(int)(numb->pos_x + 1)][(int)(numb->pos_y + 1)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 200 && numb->x < WIN_LENGHT           \
           - 160 && numb->y > WIN_WIDTH - 120 && numb->y < WIN_WIDTH - 80)
    {
      if (ptr->map[(int)(numb->pos_x + 1)][(int)(numb->pos_y + 1)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 160 && numb->x < WIN_LENGHT           \
           - 120 && numb->y > WIN_WIDTH - 120 && numb->y < WIN_WIDTH - 80)
    {
      if (ptr->map[(int)(numb->pos_x - 1)][(int)(numb->pos_y - 1)] == '1')
        change_color(color, 0, 0, 0);
    }
}

void		my_wall_minimap(t_ptr *ptr, t_numb *numb, t_color *color)
{
  if (numb->x > WIN_LENGHT - 200 && numb->x < WIN_LENGHT                \
      - 160 && numb->y > WIN_WIDTH - 160 && numb->y < WIN_WIDTH - 120)
    {
      if (ptr->map[(int)(numb->pos_x)][(int)(numb->pos_y - 1)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 120 && numb->x < WIN_LENGHT           \
           - 80 && numb->y > WIN_WIDTH - 160 && numb->y < WIN_WIDTH - 120)
    {
      if (ptr->map[(int)(numb->pos_x)][(int)(numb->pos_y + 1)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 160 && numb->x < WIN_LENGHT           \
           - 120 && numb->y > WIN_WIDTH - 200 && numb->y < WIN_WIDTH - 160)
    {
      if (ptr->map[(int)(numb->pos_x + 1)][(int)(numb->pos_y)] == '1')
        change_color(color, 0, 0, 0);
    }
  else if (numb->x > WIN_LENGHT - 160 && numb->x < WIN_LENGHT           \
           - 120 && numb->y > WIN_WIDTH - 12 && numb->y < WIN_WIDTH - 80)
    {
      if (ptr->map[(int)(numb->pos_x - 1)][(int)(numb->pos_y)] == '1')
        change_color(color, 0, 0, 0);
    }
}
