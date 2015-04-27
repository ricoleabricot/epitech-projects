/*
** display.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Dec  5 11:27:55 2013 Pierrick Gicquelais
** Last update Sun Dec  8 13:48:45 2013 Pierrick Gicquelais
*/

#include "../include/fdf.h"

int	my_pixel_put_to_image(t_dat *dat, char *data, int modX, int modY)
{
  if (dat->bpp == 0 || dat->sizeline == 0)
    my_error("Bits per pixel or sizeline null");
  data[(modX + modY)] = 0xFF;
  data[(modX + modY) + 1] = 0xFF;
  data[(modX + modY) + 2] = 0xFF;
  data[(modX + modY) + 3] = 0;
  return (0);
}

void	display_map(t_list **list, t_dat *dat, char *data)
{
  t_list	*point1;
  t_list	*point2;

  point1 = *list;
  while (point1 != NULL)
    {
      point2 = *list;
      while (point2 != NULL)
	{
	  if (point1->x == point2->x - 1 && point1->y == point2->y)
	    my_draw(dat, data, point1, point2);
	  if (point1->y == point2->y - 1 && point1->x == point2->x)
	    my_draw(dat, data, point1, point2);
	  point2 = point2->next;
	}
      point1 = point1->next;
    }
}
