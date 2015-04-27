/*
** list2.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 14:13:31 2014 Pierrick Gicquelais
** Last update Wed Jan 15 16:18:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"../select.h"

void		aff_list(t_list *list)
{
  t_node	*noeud;

  if (list == NULL)
    my_putstr("List null");
  else
    {
      noeud = list->head;
      while (noeud)
	{
	  my_putstr(noeud->choice);
	  my_putchar('\n');
	  noeud = noeud->next;
	}
    }
}
