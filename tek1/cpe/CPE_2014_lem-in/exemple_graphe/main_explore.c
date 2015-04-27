/*
** main_explore.c for  in /u/guest/hotplug/hotplug
** 
** Made by guillaumE clauzon
** Login   <hotplug@epita.fr>
** 
** Started on  Mon Mar 17 00:50:18 2003 guillaumE clauzon
** Last update Mon Mar 17 00:50:19 2003 guillaumE clauzon
*/

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "explore.h"



int		main(int	argc,
		     char	*argv[])
{
  t_graphe	*graphe;
  int		*done;

  graphe = str_to_graphe("2-3 4-5 3-5 5-1 5-6");

  done = malloc((get_max_sommet(graphe) + 1) * sizeof (int));
  memset(done, 0, sizeof (done));
  parcours_prof(graphe, -1, done, 0);
  return (0);
}
