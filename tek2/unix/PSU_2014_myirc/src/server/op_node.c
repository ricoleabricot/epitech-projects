/*
** op_node.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Apr  8 17:27:24 2015 Pierrick Gicquelais
** Last update Thu Apr  9 13:37:52 2015 Pierrick Gicquelais
*/

#include	"op.h"

t_op		*first_op(t_op *op)
{
  if (op != NULL)
    while (op->prev != NULL)
      op = op->prev;
  return (op);
}

t_op		*last_op(t_op *op)
{
  if (op != NULL)
    while (op->next != NULL)
      op = op->next;
  return (op);
}

static t_op	*pop_element(t_op *ops, t_op *tmp)
{
  if (ops->prev == NULL && ops->next != NULL)
    {
      ops->next->prev = NULL;
      ops = ops->next;
    }
  else if (ops->prev != NULL && ops->next == NULL)
    {
      ops->prev->next = NULL;
      ops = ops->prev;
    }
  else if (ops->prev != NULL && ops->next != NULL)
    {
      ops->prev->next = tmp->next;
      ops->next->prev = tmp->prev;
      ops = ops->prev;
    }
  else
    ops = NULL;

  return (ops);
}

t_op		*pop_op(t_op *ops, char *nick)
{
  t_op		*tmp;

  while (ops != NULL && strcmp(ops->nick, nick) != 0)
    ops = ops->next;

  if (ops != NULL)
    {
      tmp = ops;
      ops = pop_element(ops, tmp);
      free_op(tmp);
    }

  return (first_op(ops));
}

bool		op_exists(t_op *ops, char *nick)
{
  ops = first_op(ops);
  while (ops != NULL)
    {
      if (strcmp(ops->nick, nick) == 0)
	return (true);
      ops = ops->next;
    }
  return (false);
}
