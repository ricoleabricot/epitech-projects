/*
** map.c for zappy in /home/boisso_c/rendu/PSU_2014_zappy
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 22 17:33:05 2015 Christian Boisson
** Last update Wed Jul  1 11:14:53 2015 Pierrick Gicquelais
*/

#include		"server/map.h"

void			move_player_to_pos(t_list *map, t_player *player, \
					   int x, int y)
{
  t_case		*old_cas;
  t_case		*new_cas;

  if (map && player)
    {
      old_cas = find_case_by_index(map, player->x, player->y);
      new_cas = find_case_by_index(map, x, y);
      if (old_cas && new_cas)
	{
	  old_cas->player = pop_list(old_cas->player, player);
	  player->x = x;
	  player->y = y;
	  new_cas->player = append_list(new_cas->player, player);

	  player->spell = false;
	}
    }
}

static void		generate_case(t_case *tmp)
{
  static int		droptable[] = DROPTABLE;
  unsigned int		mask;
  int			random;
  int			tmp_rand;
  int			i;

  i = 0;
  mask = 0x000F;
  random = rand();
  while (i < RESOURCES)
    {
      tmp_rand = random & mask;
      if (tmp_rand < droptable[i])
	++tmp->resources[i];
      ++i;
      random >>= 4;
    }
}

void			generate_resources(t_list *map)
{
  t_list		*tmp;
  t_list		*y_tmp;

  if (map)
    {
      tmp = map->begin;
      while (tmp)
	{
	  y_tmp = tmp->data;
	  while (y_tmp)
	    {
	      if (y_tmp->data)
		generate_case(y_tmp->data);
	      y_tmp = y_tmp->next;
	    }
	  tmp = tmp->next;
	}
    }
}

void			free_map(t_list *map)
{
  t_list		*tmp;
  t_list		*y_tmp;

  if (map)
    {
      tmp = map->begin;
      while (tmp)
	{
	  y_tmp = tmp->data;
	  while (y_tmp)
	    {
	      if (y_tmp->data)
		free_list_player(((t_case *)y_tmp->data)->player);
	      if (y_tmp->data)
		free(y_tmp->data);
	      y_tmp->data = NULL;
	      y_tmp = y_tmp->next;
	    }
	  free_list(tmp->data);
	  tmp->data = NULL;
	  tmp = tmp->next;
	}
      free_list(map->begin);
    }
}
