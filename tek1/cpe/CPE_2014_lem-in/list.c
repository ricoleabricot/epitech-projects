/*
** list.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 17 12:36:37 2014 Pierrick Gicquelais
** Last update Fri Apr 18 15:48:33 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"funct.h"

t_list		*new_adj_list(int submit)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    my_error("Error with a memory allocation", 2);
  list->num_sommet = submit;
  list->sommet_adj = 0;
  list->adj = NULL;
  list->next = NULL;
  return (list);
}

void		add_adjacence(t_list *list, int submit, int count)
{
  int		i;

  for (i = 0; i < list->sommet_adj; i++)
    if (list->adj[i] == submit)
      return;
  list->sommet_adj++;
  list->adj = realloc(list->adj, sizeof (int) * list->sommet_adj);
  list->adj[list->sommet_adj - 1] = submit;
  list->count = realloc(list->count, sizeof (int) * list->sommet_adj);
  list->count[list->sommet_adj - 1] = count;
}
