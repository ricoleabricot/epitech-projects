/*
** op.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Apr  8 17:09:50 2015 Pierrick Gicquelais
** Last update Sun Apr 12 19:48:40 2015 Pierrick Gicquelais
*/

#include	"op.h"
#include	"user.h"
#include	"xmalloc.h"
#include	"swrite.h"

t_op		*new_op(void)
{
  t_op		*op;

  op = xmalloc(sizeof(t_op));

  op->prev = NULL;
  op->next = NULL;

  op->nick = NULL;

  return (op);
}

t_op		*append_op(t_op *old, char *nick)
{
  t_op		*new;

  new = new_op();

  if ((old = last_op(old)) != NULL)
    old->next = new;

  new->nick = strdup(nick);
  new->prev = old;
  new->next = NULL;

  return (new);
}

void		aff_ops(t_op *op, t_user *users, int fd)
{
  char		ret[124];
  int		cpt;

  cpt = 0;
  op = first_op(op);
  while (op != NULL)
    {
      if (user_exists(users, op->nick))
	{
	  sprintf(ret, "393 RPL_USERS :%s\r\n", op->nick);
	  swrite(fd, ret);
	  cpt++;
	}
      op = op->next;
    }

  if (cpt == 0)
    swrite(fd, "395 RPL_NOUSERS :No ops logged in\r\n");
}

void		free_op(t_op *op)
{
  if (op != NULL)
    {
      if (op->nick != NULL)
	free(op->nick);
      free(op);
    }
}

void		free_ops(t_op *op)
{
  t_op		*tmp;

  op = first_op(op);
  while (op != NULL)
    {
      tmp = op;
      op = op->next;
      free_op(tmp);
    }
}
