/*
** list.c for zappy in /home/boisso_c/rendu/PSU_2014_zappy/src/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 22 15:34:40 2015 Christian Boisson
** Last update Thu Jul  2 22:02:43 2015 rousse_3
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"server/xmalloc.h"
#include	"server/list.h"

t_list		*append_list(t_list *list, void *data)
{
  t_list	*tmp;
  t_list	*new;

  new = xmalloc(sizeof(t_list));
  new->next = NULL;
  new->data = data;
  if (list == NULL)
    {
      new->prev = NULL;
      new->begin = new;
      return (new);
    }
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  new->prev = tmp;
  tmp->next = new;
  tmp = list;
  while (tmp->prev)
    tmp = tmp->prev;
  new->begin = tmp;
  return (list->begin);
}

t_list		*pop_list(t_list *list, void *to_rm)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (tmp->data == to_rm)
	return (delete_list(tmp));
      tmp = tmp->next;
    }
  return (list->begin);
}

t_list		*delete_list(t_list *to_rm)
{
  t_list	*begin;
  t_list	*tmp;

  begin = NULL;
  tmp = to_rm;
  if (to_rm)
    {
      if (to_rm == to_rm->begin)
	begin = to_rm->begin->next;
      else
	begin = to_rm->begin;
      if (to_rm->prev)
	to_rm->prev->next = to_rm->next;
      if (to_rm->next)
	to_rm->next->prev = to_rm->prev;
      free(to_rm);
      tmp = begin;
      while (tmp)
	{
	  tmp->begin = begin;
	  tmp = tmp->next;
	}
    }
  return (begin);
}

t_list		*begin_list(t_list *list)
{
  return (list->begin);
}

void		free_list(t_list *begin)
{
  t_list	*tmp;

  if (begin)
    {
      tmp = begin->begin;
      while ((tmp = delete_list(tmp)));
    }
}
