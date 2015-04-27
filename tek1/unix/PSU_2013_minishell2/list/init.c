/*
** init.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 16:23:58 2014 Pierrick Gicquelais
** Last update Fri Feb 28 18:31:13 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../shell2.h"

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    my_error("Error 6: Error with a memory allocation", 6);
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
  return (list);
}

t_node		*init_node()
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    my_error("Error 7: Error with a memory allocation", 7);
  node->next = NULL;
  return (node);
}

