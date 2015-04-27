/*
** put.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 20:31:31 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:11:50 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../shell2.h"

void		append_list(t_list *list, char *str)
{
  t_node	*node;

  if (list == NULL)
    my_error("Error 52: List null", 52);
  node = init_node();
  node->env = my_strlcpy(str, 0);
  list->count++;
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
  free(node->env);
  free(node);
}

void		delete_list(t_list *list, char *str, int option)
{
  t_node	*node;

  node = list->head;
  while (node && my_strncmp(str, node->env, my_strlen(str)) != 0)
    node = node->next;
  if (node)
    {
      delete_node(list, node);
      if (option == 1)
	list->count--;
    }
}
