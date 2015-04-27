/*
** graph.h for  in /u/guest/hotplug/hotplug
** 
** Made by guillaumE clauzon
** Login   <hotplug@epita.fr>
** 
** Started on  Mon Mar 17 00:50:30 2003 guillaumE clauzon
** Last update Mon Mar 17 00:50:31 2003 guillaumE clauzon
*/


#ifndef GRAPH_H_
# define GRAPH_H_

struct			s_adj_list
{
  int			numero_sommet;          /* identifiant du sommet */
  
  int			nb_sommet_adjacent;     /* nombre de sommet adjacent */
  int			*adjacents;             /* sommets adjacents */
  unsigned int		*cout;			/* cout vers les adjacents */
  
  struct s_adj_list	*next;
};

typedef struct s_adj_list	t_adj_list;



struct			s_graphe
{
  int			nb_sommet;              /* nombre de sommets */

  t_adj_list		*adj_list;
};

typedef struct s_graphe		t_graphe;



void		graph_insert_arc(t_graphe		*graphe,
				 int			numero_sommet1,
				 int			numero_sommet2,
				 int			cout);

t_graphe	*new_graphe(void);

t_graphe	*str_to_graphe(const char	*str);

t_graphe	*str_to_graphe_2(const char	*str);

int		get_max_sommet(t_graphe		*g);

#endif
/*
 * ! GRAPH_H_
 */
