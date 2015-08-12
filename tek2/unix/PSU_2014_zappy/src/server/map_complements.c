/*
** map_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:31:58 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:57:01 2015 Pierrick Gicquelais
*/

#include	"server/map.h"

static t_case		*find_case(t_list *tmp, int y)
{
  t_list		*y_tmp;
  int			i;

  if (tmp)
    {
      y_tmp = tmp->data;
      i = 0;
      while (y_tmp && i < y)
	{
	  i++;
	  y_tmp = y_tmp->next;
	}

      if (y_tmp)
	return (y_tmp->data);
    }
  return (NULL);
}

t_case			*find_case_by_index(t_list *map, int x, int y)
{
  t_list		*tmp;
  int			i;

  if (map)
    {
      tmp = map->begin;
      i = 0;
      while (tmp && i < x)
	{
	  i++;
	  tmp = tmp->next;
	}

      return (find_case(tmp, y));
    }
  return (NULL);
}

void			clear_case(t_case *pos)
{
  pos->resources[LINEMATE] = 0;
  pos->resources[DERAUMERE] = 0;
  pos->resources[SIBUR] = 0;
  pos->resources[MENDIANE] = 0;
  pos->resources[PHIRAS] = 0;
  pos->resources[THYSTAME] = 0;
}
