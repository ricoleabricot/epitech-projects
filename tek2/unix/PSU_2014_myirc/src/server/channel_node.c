/*
** channel_node.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:27:30 2015 Pierrick Gicquelais
** Last update Fri Apr 10 18:04:26 2015 Pierrick Gicquelais
*/

#include	"channel.h"

t_channel	*first_channel(t_channel *ch)
{
  if (ch != NULL)
    while (ch->prev != NULL)
      ch = ch->prev;
  return (ch);
}

t_channel	*last_channel(t_channel *ch)
{
  if (ch != NULL)
    while (ch->next != NULL)
      ch = ch->next;
  return (ch);
}

static t_channel *pop_element(t_channel *chs, t_channel *tmp)
{
  if (chs->prev == NULL && chs->next != NULL)
    {
      chs->next->prev = NULL;
      chs = chs->next;
    }
  else if (chs->prev != NULL && chs->next == NULL)
    {
      chs->prev->next = NULL;
      chs = chs->prev;
    }
  else if (chs->prev != NULL && chs->next != NULL)
    {
      chs->prev->next = tmp->next;
      chs->next->prev = tmp->prev;
      chs = chs->prev;
    }
  else
    chs = NULL;

  return (chs);
}

t_channel	*pop_channel(t_channel *chs, char *name)
{
  t_channel	*tmp;

  chs = get_channel_by_name(chs, name);

  if (chs != NULL)
    {
      tmp = chs;
      chs = pop_element(chs, tmp);
      free_channel(tmp);
    }

  return (first_channel(chs));
}
