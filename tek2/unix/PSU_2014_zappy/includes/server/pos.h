/*
** pos.h for zappy in /home/boisso_c/rendu/PSU_2014_zappy/includes/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Jun 26 12:29:00 2015 Christian Boisson
** Last update Mon Jun 29 17:01:42 2015 Christian Boisson
*/

#ifndef			POS_H_
# define		POS_H_

void			correct_pos(t_server *server, int *x, int *y);
void			get_new_pos(t_server *server, t_player *player, \
				    int *x, int *y);

#endif			/* !POS_H_ */
