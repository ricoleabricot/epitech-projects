/*
** graphe.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 17 12:23:13 2014 Pierrick Gicquelais
** Last update Fri Apr 18 15:48:24 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"funct.h"

t_graf		*init_graphe()
{
  t_graf	*graf;

  if ((graf = malloc(sizeof(t_graf))) == NULL)
    my_error("Error with a memory allocation", 1);
  graf->sommet = 0;
  graf->list = NULL;
  return (graf);
}

void		graphe_insert_arc(t_graf *graf, int submit1, int submit2, int count)
{
  t_list	*list1;
  t_list	*list2;

  list1 = graphe_insert_sommet(graf, submit1);
  list2 = graphe_insert_sommet(graf, submit2);
  add_adjacence(list1, submit1, count);
  add_adjacence(list2, submit2, count);
}

t_list		*graphe_insert_sommet(t_graf *graf, int submit)
{
  t_list	*elem;
  t_list	*prev;

  elem = prev = graf->list;
  while (elem != NULL)
    {
      if (elem->num_sommet == submit)
	return (elem);
      prev = elem;
      elem = elem->next;
    }
  graf->sommet++;
  if (!(graf->list))
    return (graf->list = new_adj_list(submit));
  else
    return (prev->next = new_adj_list(submit));
}
