/*
** list_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:31:00 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:31:13 2015 Pierrick Gicquelais
*/

#include	"server/list.h"

int		list_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  if (list)
    {
      tmp = list->begin;
      while (tmp)
	{
	  i++;
	  tmp = tmp->next;
	}
    }

  return (i);
}
