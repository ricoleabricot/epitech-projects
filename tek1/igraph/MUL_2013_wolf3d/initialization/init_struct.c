/*
** init.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jan  7 17:02:59 2014 Pierrick Gicquelais
** Last update Fri Jan 10 01:19:57 2014 Pierrick Gicquelais
*/

#include	"../include/wolf.h"

t_ptr		*init_ptr(t_wolf *wolf)
{
  if ((wolf->ptr = malloc(sizeof(t_ptr))) == NULL)
    my_error("Error with a memory allocation");
  return (wolf->ptr);
}

t_numb		*init_numb(t_wolf *wolf)
{
  if ((wolf->numb = malloc(sizeof(t_numb))) == NULL)
    my_error("Error with a memory allocation");
  return (wolf->numb);
}

t_color		*init_color(t_wolf *wolf)
{
  if ((wolf->color = malloc(sizeof(t_color))) == NULL)
    my_error("Error with a memory allocation");
  return (wolf->color);
}

t_algo		*init_algo(t_wolf *wolf)
{
  if ((wolf->algo = malloc(sizeof(t_algo))) == NULL)
    my_error("Error with a memory allocation");
  return (wolf->algo);
}

t_move		*init_move(t_wolf *wolf)
{
  if ((wolf->move = malloc(sizeof(t_wolf))) == NULL)
    my_error("Error with a memory allocation");
  return (wolf->move);
}
