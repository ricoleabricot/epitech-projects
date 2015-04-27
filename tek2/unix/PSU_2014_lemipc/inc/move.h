/*
** move.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Mar  8 19:30:10 2015 Pierrick Gicquelais
** Last update Sun Mar  8 19:30:35 2015 Pierrick Gicquelais
*/

#ifndef		MOVE_H
# define	MOVE_H

# include	<time.h>
# include	<stdlib.h>
# include	"lemipc.h"

# define	MOVE_DOWN(a)	a - 100 < 0 ? 0 : a - 100
# define	MOVE_UP(a)	a + 100 > SHM_SIZE ? SHM_SIZE : a + 100
# define	MOVE_LEFT(a)	a - 1 < 0 ? 0 : a - 1
# define	MOVE_RIGHT(a)	a + 1 > SHM_SIZE ? SHM_SIZE : a + 1

int		random_move(t_ipc *ipc);
int		go_to_enemy(int en_pos, t_ipc *ipc, int first);

#endif		/* !MOVE_H */
