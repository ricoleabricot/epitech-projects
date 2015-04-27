/*
** action.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 20:33:12 2014 Pierrick Gicquelais
** Last update Mon Jan  6 20:39:55 2014 Pierrick Gicquelais
*/

#include	"../push.h"

void		swap_list(t_list *list)
{
  t_node	*noeud;
  t_node	*noeud2;

  if (list->head && list->head->next)
    {
      if (list_count(list) == 2)
        rotate_list(list);
      else
        {
          noeud = list->head;
          noeud2 = list->head->next;
          noeud->next = noeud2->next;
          noeud2->next = noeud;
          list->head = noeud2;
        }
    }
}

void            rotate_list(t_list *list)
{
  if (list_count(list) > 1)
    {
      append_list(list, list->head->nb);
      pop_list(list);
    }
}

void		pop_list(t_list *list)
{
  t_node	*noeud;

  noeud = list->head;
  list->head = noeud->next;
  free(noeud);
}
