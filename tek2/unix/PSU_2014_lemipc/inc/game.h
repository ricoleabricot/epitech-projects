/*
** game.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar  3 09:39:02 2015 Pierrick Gicquelais
** Last update Sun Mar  8 12:19:18 2015 Pierrick Gicquelais
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>

# include	"lemipc.h"

void		init_game(t_ipc *);
void		play_game(t_ipc *);
void		end_game(t_ipc *);
int		win_game(t_ipc *);

#endif		/* !GAME_H_ */
