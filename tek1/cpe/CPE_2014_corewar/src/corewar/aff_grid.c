/*
** aff_grid.c for corewar in /home/gicque_p/local/cpe/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr 14 13:03:14 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:12:27 2014 Pierrick Gicquelais
*/

#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		my_put_pixel_to_image(t_vm *vm, int x, int y, int color)
{
  int		char_place;

  if (x < WIN_X && y < WIN_Y && x >= 0 && y >= 0)
    {
      char_place = ((x * vm->ptr->bpp / 8) + (y * vm->ptr->sizeline));
      *(vm->ptr->data + char_place) = (color) & 0xFF;
      *(vm->ptr->data + char_place + 1) = (color >> 8) & 0xFF;
      *(vm->ptr->data + char_place + 2) = (color >> 16) & 0xFF;
      *(vm->ptr->data + char_place + 3) = 0x00;
    }
}

void		draw_line(t_vm *vm, int points[4])
{
  int		i;

  if (points[0] == points[2])
    {
      i = points[1];
      while (i <= points[3])
	{
	  my_put_pixel_to_image(vm, points[0], i, 0xFFFFFF);
	  i++;
	}
    }
  else
    {
      i = points[0];
      while (i <= points[2])
	{
	  my_put_pixel_to_image(vm, i, points[1], 0xFFFFFF);
	  i++;
	}
    }
}

void		aff_grid(t_vm *vm)
{
  int		points[4];

  points[0] = 16;
  points[1] = 36;
  points[2] = 784;
  points[3] = 36;
  while (points[1] < 565)
    {
      draw_line(vm, points);
      points[1] = points[1] + 11;
    }
  points[0] = 16;
  points[1] = 36;
  points[2] = 16;
  points[3] = 564;
  while (points[0] < 786)
    {
      draw_line(vm, points);
      points[0] = points[0] + 6;
      points[2] = points[2] + 6;
    }
}
