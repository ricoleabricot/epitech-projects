/*
** key.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jan 18 09:10:31 2014 Pierrick Gicquelais
** Last update Sun Jan 19 22:09:49 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../select.h"

void		space_key(t_list *list_final, t_node *node)
{
  tputs(tgetstr("ue", NULL), 1, my_putchar);
  tputs(tgetstr("mr", NULL), 1, my_putchar);
  if (node->back == 0)
    {
      node->back = 1;
      append_list(list_final, node->choice);
    }
  else
    {
      tputs(tgetstr("me", NULL), 1, my_putchar);
      node->back = 0;
      delete_list(list_final, node->choice);
    }
}

void		enter_key(struct termios *t, t_list *list)
{
  t_node	*node;

  canon_attr(t);
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  tputs(tgetstr("me", NULL), 1, my_putchar);
  node = list->head;
  while (node)
    {
      my_putstr_final(node->choice);
      if (node->next)
        my_putchar(' ');
      node = node->next;
    }
  my_putchar('\n');
  exit(EXIT_SUCCESS);
}

void		echap_key(struct termios *t)
{
  canon_attr(t);
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  tputs(tgetstr("me", NULL), 1, my_putchar);
  exit(EXIT_SUCCESS);
}

t_node		*down_key(t_node *node, int *i)
{
  (*i)++;
  tputs(tgetstr("me", NULL), 1, my_putchar);
  my_put_spec_str(node->choice, node->back);
  node = node->next;
  return (node);
}

t_node		*up_key(t_node *node, int *i)
{
  (*i)--;
  tputs(tgetstr("me", NULL), 1, my_putchar);
  my_put_spec_str(node->choice, node->back);
  node = node->prev;
  return (node);
}
