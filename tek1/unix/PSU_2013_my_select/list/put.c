/*
** put.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 20:31:31 2014 Pierrick Gicquelais
** Last update Sun Jan 19 21:14:33 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"../select.h"

void		append_list(t_list *list, char *str)
{
  t_node	*node;

  if (list == NULL)
    my_error("List null");
  node = init_node();
  node->back = 0;
  node->choice = str;
  node->next = NULL;
  if (list->head == NULL)
    {
      node->prev = NULL;
      list->head = node;
      list->tail = node;
    }
  else
    {
      list->tail->next = node;
      node->prev = list->tail;
      list->tail = node;
    }
}

void		delete_node(t_list *list, t_node *node)
{
  if (node->next == NULL)
    {
      list->tail = node->prev;
      list->tail->next = NULL;
    }
  else if (node->prev == NULL)
    {
      list->head = node->next;
      list->head->prev = NULL;
    }
  else
    {
      node->next->prev = node->prev;
      node->prev->next = node->next;
    }
  free(node);
}

void		delete_list(t_list *list, char *str)
{
  t_node	*node;
  int		found;

  node = list->head;
  found = 0;
  while (node && found == 0)
    {
      if (my_strcmp(node->choice, str) == 0)
	{
	  delete_node(list, node);
	  found = 1;
	}
      else
	node = node->next;
    }
}
