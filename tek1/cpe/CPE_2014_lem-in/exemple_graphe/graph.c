/*
** graph.c for  in /u/guest/hotplug/hotplug
** 
** Made by guillaumE clauzon
** Login   <hotplug@epita.fr>
** 
** Started on  Mon Mar 17 00:50:36 2003 guillaumE clauzon
** Last update Mon Mar 17 00:50:37 2003 guillaumE clauzon
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"



/*
 * Retourne une liste d'adjacence vide associee au sommet passe en parametre
 */
t_adj_list	*new_adj_list(int	numero_sommet)
{
  t_adj_list	*new_adj;

  new_adj = malloc(sizeof (t_adj_list));
  new_adj->numero_sommet = numero_sommet;
  new_adj->nb_sommet_adjacent = 0;
  new_adj->adjacents = NULL;
  new_adj->next = NULL;
  return (new_adj);
}


/*
 * Retourne le plus grand numero de sommet du graphe
 */
int		get_max_sommet(t_graphe		*g)
{
  int		max = 0;
  t_adj_list	*p;

  p = g->adj_list;
  while (p)
    {
      if (p->numero_sommet > max)
	max = p->numero_sommet;
      p = p->next;
    }

  return (max);
}


/*
 * Insere le sommet demande dans le graph et retourne la liste
 * d'adjacence qui lui correspond. Si le sommet existe deja, la
 * fonction renvoie la liste d'adjacence existente
 */
static t_adj_list	*graph_insert_sommet(t_graphe	*graphe,
					     int	numero_sommet)
{
  t_adj_list		*p;
  t_adj_list		*prev;

  p = prev = graphe->adj_list;
  while (p)
    {
      if (p->numero_sommet == numero_sommet)
	return (p);
      prev = p;
      p = p->next;
    }

  graphe->nb_sommet++;
  if (!graphe->adj_list)
    return (graphe->adj_list = new_adj_list(numero_sommet));
  else
    return (prev->next = new_adj_list(numero_sommet));
}



/*
 * Ajoute le sommet passe en parametre a la liste d'adjacence
 */

static void	add_adjacence(t_adj_list		*adj,
			      int			numero_sommet,
			      int			cout)
{
  int		i;

  for (i = 0; i < adj->nb_sommet_adjacent; i++)
    if (adj->adjacents[i] == numero_sommet)
      return;
  adj->nb_sommet_adjacent++;
  adj->adjacents = realloc(adj->adjacents, 
				  sizeof (int) * adj->nb_sommet_adjacent);
  adj->adjacents[adj->nb_sommet_adjacent - 1] = numero_sommet;
  adj->cout = realloc(adj->cout, 
				  sizeof (int) * adj->nb_sommet_adjacent);
  adj->cout[adj->nb_sommet_adjacent - 1] = cout;
}




/*
 * Insere l'arc demande dans le graphe, le sommet1 devient adjacent au
 * sommet2 et le sommet2 adjacent au sommet1
 */
void	graph_insert_arc(t_graphe		*graphe,
			 int			numero_sommet1,
			 int			numero_sommet2,
			 int			cout)
{
  t_adj_list	*s1;
  t_adj_list	*s2;
  
  s1 = graph_insert_sommet(graphe, numero_sommet1);
  s2 = graph_insert_sommet(graphe, numero_sommet2);
  add_adjacence(s1, numero_sommet2, cout);
  add_adjacence(s2, numero_sommet1, cout);
}



/*
 * Retourne un graphe vide
 */
t_graphe	*new_graphe(void)
{
  t_graphe	*new_graphe;

  new_graphe = malloc(sizeof (t_graphe));
  new_graphe->nb_sommet = 0;
  new_graphe->adj_list = NULL;

  return (new_graphe);
}




/*
 * Retourne un graphe correspondant a celui qui est decrit dans la
 * chaine passee en parametre ("s1-s2 s2-s4 ... sn-sm")
 */
t_graphe	*str_to_graphe(const char	*str)
{
  t_graphe	*graphe;
  int		s1;
  int		s2;

  graphe = new_graphe();
  while (*str)
    {
      s1 = atoi(str);
      while (*str && isdigit(*str))
	str++;
      str++;
      s2 = atoi(str);
      while (*str && isdigit(*str))
	str++;
      if (*str)
	str++;
      if (s1 < 0 || s2 < 0)
	break;
      graph_insert_arc(graphe, s1, s2, 1);
    }  
  return (graphe);
}





/*
 * Retourne un graphe correspondant a celui qui est decrit dans la
 * chaine passee en parametre ("s1-s2-cout s2-s4-cout ... sn-sm-cout")
 */


t_graphe	*str_to_graphe_2(const char	*str)
{
  t_graphe	*graphe;
  int		s1;
  int		s2;
  int		cout;
  
  graphe = new_graphe();
  while (*str)
    {
      s1 = atoi(str);
      while (*str && isdigit(*str))
	str++;
      str++;
      s2 = atoi(str);
      while (*str && isdigit(*str))
	str++;
      str++;
      cout = atoi(str);
      while (*str && isdigit(*str))
	str++;
      str++;
      
      if (s1 < 0 || s2 < 0 || cout < 0)
	break;
      graph_insert_arc(graphe, s1, s2, cout);
    }
  
  return (graphe);
}
