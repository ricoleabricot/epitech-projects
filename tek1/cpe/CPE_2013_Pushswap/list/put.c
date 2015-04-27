/*
** put.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 20:31:31 2014 Pierrick Gicquelais
** Last update Mon Jan  6 20:39:47 2014 Pierrick Gicquelais
*/

#include	"../push.h"

void		append_list(t_list *list, int number)
{
  t_node	*noeud;

  if (list == NULL)
    my_error("List null");
  noeud = init_node();
  noeud->nb = number;
  if (list->head == NULL)
    {
      list->head = noeud;
      list->tail = noeud;
    }
  else
    {
      list->tail->next = noeud;
      list->tail = noeud;
    }
}

void		push_list(t_list *list, int number)
{
  t_node	*noeud;

  noeud = init_node();
  noeud->nb = number;
  if (list->head == NULL)
    {
      list->head = noeud;
      list->tail = noeud;
    }
  else
    {
      noeud->next = list->head;
      list->head = noeud;
    }
}
