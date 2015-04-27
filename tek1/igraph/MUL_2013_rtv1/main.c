/*
** main.c for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb  7 09:10:58 2014 Pierrick Gicquelais
** Last update Fri Mar 14 09:37:41 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	"struct.h"
#include	"funct.h"
#include	"maccro.h"

int		main()
{
  t_rt		*rt;

  if ((rt = malloc(sizeof(t_rt))) == NULL)
    my_error("Error 1: Error with a memory Allocation", 1);
  my_init(rt);
  remplis_img(rt);
  my_hook(rt);
  return (0);
}
