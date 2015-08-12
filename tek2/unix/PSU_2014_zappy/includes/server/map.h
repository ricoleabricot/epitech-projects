/*
** map.h for zappy in /home/boisso_c/rendu/PSU_2014_zappy
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 22 17:35:23 2015 Christian Boisson
** Last update Tue Jun 30 17:00:04 2015 Pierrick Gicquelais
*/

#ifndef		MAP_H_
# define	MAP_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"list.h"
# include	"case.h"
# include	"player.h"

void		move_player_to_pos(t_list *map, t_player *player, \
					   int x, int y);

void		generate_resources(t_list *);
void		free_map(t_list *);

t_case		*find_case_by_index(t_list *, int, int);

#endif			/* !MAP_H_ */
