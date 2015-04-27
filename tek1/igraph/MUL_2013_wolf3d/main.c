/*
** main.c for wolf 3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 10 09:04:14 2013 Pierrick Gicquelais
** Last update Fri Jan 10 01:01:35 2014 Pierrick Gicquelais
*/

#include	"include/wolf.h"

int		main()
{
  t_wolf	*wolf;

  if ((wolf = malloc(sizeof(t_wolf))) == NULL)
    my_error("Error with a memory allocation");
  my_init(wolf);
  my_parsing(wolf->ptr);
  my_hook(wolf);
  return (0);
}
