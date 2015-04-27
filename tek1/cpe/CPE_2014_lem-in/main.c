/*
** main.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 17 10:57:18 2014 Pierrick Gicquelais
** Last update Fri Apr 18 15:47:01 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"funct.h"

int		main()
{
  t_graf	*graf;

  graf = init_graphe();
  my_parsing(graf);
  free(graf);
  return (0);
}
