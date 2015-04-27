/*
** init.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 16:23:58 2014 Pierrick Gicquelais
** Last update Mon Jan  6 20:39:36 2014 Pierrick Gicquelais
*/

#include	"../push.h"

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    my_error("Error with a memory allocation");
  list->head = NULL;
  list->tail = NULL;
  return (list);
}

t_node		*init_node()
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    my_error("Error with a memory allocation");
  node->nb = 0;
  node->next = NULL;
  return (node);
}

