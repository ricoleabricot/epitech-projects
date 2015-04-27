/*
** move.c for lemipc in /home/barbu/lemipc/src
** 
** Made by Cyril Labitte
** Login   <labitt_c@epitech.eu>
** 
** Started on  Sun Mar 08 16:18:44 2015 Cyril Labitte
** Last update Sun Mar  8 20:01:59 2015 Pierrick Gicquelais
*/

#include	"move.h"

int		random_move(t_ipc *ipc)
{
  int		move;

  srand(time(NULL));
  move = rand() % 4;
  if (move == 0 && (MOVE_UP(ipc->position) == 0))
    ipc->position = MOVE_UP(ipc->position);
  else if (move == 1 && MOVE_DOWN(ipc->position) == 0)
    ipc->position = MOVE_DOWN(ipc->position);
  else if (move == 2  && MOVE_LEFT(ipc->position) == 0)
    ipc->position = MOVE_LEFT(ipc->position);
  else if (move == 3  && MOVE_RIGHT(ipc->position) == 0)
    ipc->position = MOVE_RIGHT(ipc->position);
  return (ipc->position);
}

int		go_to_enemy(int en_pos, t_ipc *ipc, int first)
{
  int		x;
  int		y;

  x = en_pos / 100;
  y = en_pos % 100;
  if (ipc->position != en_pos + first)
  {
    if (x > ipc->position / 100)
      ipc->position = MOVE_UP(ipc->position);
    else if (x < ipc->position / 100)
      ipc->position = MOVE_DOWN(ipc->position);
    else
    {
      if (y > ipc->position % 100)
	ipc->position = MOVE_UP(ipc->position);
      else if (y < ipc->position % 100)
	ipc->position = MOVE_DOWN(ipc->position);
    }
  }
  return (ipc->position);
}
