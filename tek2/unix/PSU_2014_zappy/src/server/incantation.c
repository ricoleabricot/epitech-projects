/*
** incantation.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 30 15:31:52 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:42:27 2015 Pierrick Gicquelais
*/

#include	"server/incantation.h"

bool		check_stones(t_case *pos, int level)
{
  int		*res;
  static int	stones[9][6] = {STONES};

  res = pos->resources;
  if (res[LINEMATE] == stones[level][LINEMATE - 1] &&	\
      res[DERAUMERE] == stones[level][DERAUMERE - 1] && \
      res[SIBUR] == stones[level][SIBUR - 1] && \
      res[MENDIANE] == stones[level][MENDIANE - 1] && \
      res[PHIRAS] == stones[level][PHIRAS - 1] && \
      res[THYSTAME] == stones[level][THYSTAME - 1])
    return (true);

  return (false);
}

bool		check_players(t_case *pos, int level)
{
  t_list	*tmp;
  t_player	*player;
  int		cpt;

  static int	players[9] = PLAYERS;

  tmp = pos->player;
  cpt = 0;
  while (tmp)
    {
      if (tmp->data)
	{
	  player = ((t_player *)tmp->data);
	  if (player->level == level)
	    cpt++;
	  else
	    return (false);
	}
      tmp = tmp->next;
    }

  return (cpt == players[level]);
}
