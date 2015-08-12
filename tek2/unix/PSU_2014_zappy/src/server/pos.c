/*
** pos.c for zappy in /home/boisso_c/rendu/PSU_2014_zappy/src/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Jun 26 12:22:47 2015 Christian Boisson
** Last update Mon Jun 29 18:38:09 2015 Christian Boisson
*/

#include		"server/server.h"

void			correct_pos(t_server *server, int *x, int *y)
{
  if ((*x) < 0)
    (*x) += (server->width);
  else if ((*x) > (server->width - 1))
    (*x) -= (server->width + 1);
  if ((*y) < 0)
    (*y) += (server->height);
  else if ((*y) > (server->height - 1))
    (*y) -= (server->height + 1);
}

void			get_new_pos(t_server *server, t_player *player, \
				    int *x, int *y)
{
  if (server && player)
    {
      (*x) = player->x;
      (*y) = player->y;
      if (player->orientation == NORTH)
	--(*y);
      else if (player->orientation == WEST)
	--(*x);
      else if (player->orientation == EAST)
	++(*x);
      else if (player->orientation == SOUTH)
	++(*y);
      correct_pos(server, x, y);
    }
}
