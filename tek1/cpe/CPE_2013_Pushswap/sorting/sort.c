/*
** sort.c for push_swap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan  6 16:25:39 2014 Pierrick Gicquelais
** Last update Mon Jan  6 23:03:41 2014 Pierrick Gicquelais
*/

#include	"../push.h"

int		list_count(t_list *list)
{
  t_node	*noeud;
  int		cmp;

  cmp = 0;
  noeud = list->head;
  while (noeud)
    {
      cmp++;
      noeud = noeud->next;
    }
  return (cmp);
}

int		sorted_list(t_list *list)
{
  t_node	*noeud;

  noeud = list->head;
  while (noeud->next)
    {
      if (noeud->nb > noeud->next->nb)
        return (0);
      noeud = noeud->next;
    }
  return (1);
}

void		sort_a(t_list *l_a, t_list *l_b, int option)
{
  if (option == 1)
    aff_option(l_a, l_b);
  while (l_a->head)
    {
      if (l_a->head->next && l_a->head->nb > l_a->head->next->nb)
	{
	  swap_list(l_a);
	  my_putstr("sa ");
	  if (option == 1)
	    aff_option(l_a, l_b);
	}
      push_list(l_b, l_a->head->nb);
      my_putstr("pb ");
      pop_list(l_a);
      if (option == 1)
	aff_option(l_a, l_b);
      rotate_list(l_b);
      my_putstr("rb ");
      if (option == 1)
	{
	  aff_option(l_a, l_b);
	  my_putchar('\n');
	}
    }
}

void		sort_b(t_list *l_a, t_list *l_b, int option)
{
  while (l_b->head)
    {
      if (l_b->head->next && l_b->head->nb > l_b->head->next->nb)
	{
	  swap_list(l_b);
	  my_putstr("sb ");
	  if (option == 1)
	    aff_option(l_a, l_b);
	}
      push_list(l_a, l_b->head->nb);
      my_putstr("pa ");
      pop_list(l_b);
      if (option == 1)
	aff_option(l_a, l_b);
      rotate_list(l_a);
      my_putstr("ra ");
      if (option == 1)
	{
	  aff_option(l_a, l_b);
	  my_putchar('\n');
	}
    }
}

int		sort_list(t_list *l_a, t_list *l_b, char **argv)
{
  int		i;
  int		cmp;

  i = -1;
  cmp = list_count(l_a);
  while (++i < cmp)
    {
      if (my_strcmp(argv[1], "-v") == 0 || my_strcmp(argv[2], "-v") == 0 || \
	  my_strcmp(argv[3], "-v") == 0)
	{
	  sort_a(l_a, l_b, 1);
	  sort_b(l_a, l_b, 1);
	}
      else
	{
	  sort_a(l_a, l_b, 0);
	  sort_b(l_a, l_b, 0);
	}
      if ((sorted_list(l_a)) == 1)
	return (0);
    }
  return (0);
}
