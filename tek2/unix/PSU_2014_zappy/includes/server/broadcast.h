/*
** broadcast.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 18:42:06 2015 Pierrick Gicquelais
** Last update Thu Jul  2 11:28:49 2015 Christian Boisson
*/

#ifndef		BROADCAST_H_
# define	BROADCAST_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"client.h"
# include	"swrite.h"

void		set_virtual(double *, double, int *, int);
void		set_virtual_pos(int, int *, int *, t_player *);
void		get_virtual_pos(t_player *, t_player *, int *, int *);
int		get_tmp_k(int, int, int, int);
int		alter_k(int, int);
int		get_k(t_server *, t_player *, t_player *);
void		broadcast(t_client *, char *, char);
void		broadcast_players(t_server *, t_client *, t_client *, char *);

# define	DIRTOK		{0, 5, 1}, \
				{7, 6, 8}, \
				{3, 4, 2}

#endif		/* !BROADCAST_H_ */
