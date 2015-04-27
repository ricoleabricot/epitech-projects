/*
** init.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jan 15 12:56:05 2014 Pierrick Gicquelais
** Last update Wed Jan 15 16:28:49 2014 Pierrick Gicquelais
*/

#include		<stdlib.h>
#include		"../select.h"

t_list			*init_list()
{
  t_list		*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    my_error("Error with a memory allocation");
  list->head = NULL;
  list->tail = NULL;
  return (list);
}

t_node			*init_node()
{
  t_node		*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    my_error("Error with a memory allocation");
  return (node);
}
