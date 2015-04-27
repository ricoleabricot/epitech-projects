/*
** main.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Nov 28 13:50:50 2013 Pierrick Gicquelais
** Last update Sun Dec  8 13:55:17 2013 Pierrick Gicquelais
*/

#include "include/fdf.h"

int	main(int argc, char **argv)
{
  t_ptr		*ptr;
  t_list	*list;
  t_dat		*dat;
  char		*data;

  if (argc != 2)
    my_error("There must be only one argument");
  if ((ptr = malloc(sizeof(t_ptr))) == NULL)
    my_error("Error with an allocation");
  if ((dat = malloc(sizeof(t_dat))) == NULL)
    my_error("Error with an allocation");
  list = NULL;
  my_parsing(&list, argv, dat);
  proj_iso_list(&list, dat);
  if ((ptr->mlx_ptr = mlx_init()) == NULL)
    my_error("Environment is disabled. End of Programm");
  ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, 1650, 1000);
  data = mlx_get_data_addr						\
    (ptr->img_ptr, &(dat->bpp), &(dat->sizeline), &(dat->endian));
  display_map(&list, dat, data);
  ptr->win_ptr = mlx_new_window					\
    (ptr->mlx_ptr, 1650, 1000, "Alex a ecore mange mon fdf !");
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  my_hook(ptr, &list);
  return (0);
}
