/*
** explore.c for  in /u/guest/hotplug/hotplug
** 
** Made by guillaumE clauzon
** Login   <hotplug@epita.fr>
** 
** Started on  Mon Mar 17 00:50:46 2003 guillaumE clauzon
** Last update Mon Mar 17 01:22:46 2003 guillaumE clauzon
*/

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"




/*
 * Exploration d'un graphe en profondeur
 */

/*
 * Recherche le sommet demande dans le graph et retourne la liste
 * d'adjacence qui lui correspond
 */
static t_adj_list	*find_sommet(t_graphe	*graphe,
				     int	numero_sommet)
{
  t_adj_list		*p, *prev;

  p = prev = graphe->adj_list;
  while (p)
    {
      if (p->numero_sommet == numero_sommet)
	return (p);

      prev = p;
      p = p->next;
    }
  return (NULL);
}



/*
 * Affiche "space" caracteres espace
 */
static void	print_space(int	space)
{
  while (space--)
    printf(" ");
}




/*
 * Parcours g en profondeur a partir du sommet depart (si il existe),
 * necessite un tableau done initialise a 0 de la taille du graphe, et
 * un entier space pour le decalage des printfs.
 */
void		parcours_prof(t_graphe		*g,
			      int		depart,
			      int		*done,
			      int		space)
{
  t_adj_list	*adj;
  int		i;
  
  if (depart == -1)
    adj = g->adj_list;
  else
    adj = find_sommet(g, depart);
  if (!adj)
    return;
  print_space(space);
  printf("* On part du sommet: %d\n", adj->numero_sommet);

  done[adj->numero_sommet] = 1;
  
  for (i = 0; i < adj->nb_sommet_adjacent; i++)
    {
      print_space(space);
      if (!done[adj->adjacents[i]])
	{
	  printf("--Adjacent disponible: %d -> Exploration\n\n",
		 adj->adjacents[i]);
	  parcours_prof(g, adj->adjacents[i], done, space + 4);
	}
      else
	printf("--Adjacent disponible: %d -> Deja fait\n", adj->adjacents[i]);
    }

  print_space(space);
  printf("* On quitte le sommet: %d\n\n", adj->numero_sommet);
}





