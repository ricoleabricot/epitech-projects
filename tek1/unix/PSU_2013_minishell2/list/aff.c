/*
** list2.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 14:13:31 2014 Pierrick Gicquelais
** Last update Fri Feb 28 18:08:28 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../shell2.h"

void		aff_list(t_list *list)
{
  t_node	*node;

  if (list == NULL)
    my_putstr("List null");
  else
    {
      node = list->head;
      while (node)
	{
	  my_printf("%s\n", node->env);
	  node = node->next;
	}
    }
}
