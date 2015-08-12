/*
** incantation.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 30 15:35:08 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:13:20 2015 Pierrick Gicquelais
*/

#ifndef		INCANTATION_H_
# define	INCANTATION_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>

# include	"server.h"

# define	STONES	{0, 0, 0, 0, 0, 0}, \
			{1, 0, 0, 0, 0, 0}, \
			{1, 1, 1, 0, 0, 0}, \
			{2, 0, 1, 0, 2, 0}, \
			{1, 1, 2, 0, 1, 0}, \
			{1, 2, 1, 3, 0, 0}, \
			{1, 2, 3, 0, 1, 0}, \
			{2, 2, 2, 2, 2, 1}, \
			{0, 0, 0, 0, 0, 0}

# define	PLAYERS	{0, 1, 2, 2, 4, 4, 6, 6, 0}

bool		check_stones(t_case *, int);
bool		check_players(t_case *, int);

#endif		/* !INCANTATION_H_ */
