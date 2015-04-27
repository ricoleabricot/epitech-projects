/*
** init.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 11:33:19 2014 Pierrick Gicquelais
** Last update Sat Feb 15 11:28:40 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void            init_mlx(t_ptr *ptr, t_nb *nb)
{
  if ((ptr->mlx_ptr = mlx_init()) == NULL)
    my_error("Error 1: Environment disabled. End of programm", 1);
  ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH);
  ptr->data = mlx_get_data_addr(ptr->img_ptr, &(nb->bpp), &(nb->sizeline), &(nb->endian));
  ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "Bombyx");
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

t_ptr           *init_ptr(t_bomb *bomb)
{
  if ((bomb->ptr = malloc(sizeof(t_ptr))) == NULL)
    my_error("Error 3: Memory allocation", 3);
  return (bomb->ptr);
}

t_nb            *init_nb(t_bomb *bomb)
{
  if ((bomb->nb = malloc(sizeof(t_nb))) == NULL)
    my_error("Error 4: Memory allocation", 4);
  return (bomb->nb);
}

t_color		*init_color(t_bomb *bomb)
{
  if ((bomb->color = malloc(sizeof(t_color))) == NULL)
    my_error("Error 5: Memory allocation", 5);
  return (bomb->color);
}

void            my_init(t_bomb *bomb)
{
  init_ptr(bomb);
  init_nb(bomb);
  init_color(bomb);
  bomb->nb->xo = 40;
  bomb->nb->yo = WIN_WIDTH - 30;
  bomb->nb->zoomx = 35;
  bomb->nb->zoomy = 35;
  init_mlx(bomb->ptr, bomb->nb);
}
