/*
** list2.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 14:13:31 2014 Pierrick Gicquelais
** Last update Mon Jan  6 20:46:38 2014 Pierrick Gicquelais
*/

#include	"../push.h"

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
	  my_putnbr(noeud->nb);
	  my_putchar(' ');
	  noeud = noeud->next;
	}
    }
}

void		aff_option(t_list *l_a, t_list *l_b)
{
  my_putchar('\n');
  my_putstr("List A: ");
  aff_list(l_a);
  my_putchar('\n');
  my_putstr("List B: ");
  aff_list(l_b);
  my_putchar('\n');
}
