/*
** player_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:32:55 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:59:28 2015 Pierrick Gicquelais
*/

#include	"server/player.h"

void		free_list_player(t_list *players)
{
  t_list	*tmp;

  if (players)
    {
      tmp = players->begin;
      while (tmp)
	{
	  free_player(tmp->data);
	  tmp->data = NULL;
	  tmp = tmp->next;
	}
      free_list(players);
    }
}

void		free_player(t_player *player)
{
  t_list	*tmp;

  if (player)
    {
      if (player->actions)
      {
	tmp = ((t_list *)player->actions)->begin;

	while (tmp)
	  {
	    free(tmp->data);
	    tmp->data = NULL;
	    tmp = tmp->next;
	  }
	free_list(player->actions);
      }

      if (player->team)
	free(player->team);
      free(player);
    }
}

void		level_up(t_case *pos)
{
  t_list	*tmp;
  t_player	*player;

  tmp = pos->player;
  while (tmp)
    {
      if (tmp->data)
	{
	  player = ((t_player *)tmp->data);
	  player->level++;
	}
      tmp = tmp->next;
    }
}
