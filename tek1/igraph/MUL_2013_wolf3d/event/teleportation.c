/*
** teleportation.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d/event
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jan 12 22:10:47 2014 Pierrick Gicquelais
** Last update Sun Jan 12 22:12:52 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

void		blue_tp(t_ptr *ptr, t_numb *numb)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (ptr->map[i][j++] != '2')
    {
      if (j == MAP_LENGHT - 1)
	{
	  i++;
	  j = 0;
	}
      numb->pos_x = i + 1.5;
      numb->pos_y = j + 0.5;
    }
}

void		orange_tp(t_ptr *ptr, t_numb *numb)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (ptr->map[i][j++] != '3')
    {
      if (j == MAP_LENGHT - 1)
	{
	  i++;
	  j = 0;
	}
      numb->pos_x = j + 1.5;
      numb->pos_y = i + 0.5;
    }
}
