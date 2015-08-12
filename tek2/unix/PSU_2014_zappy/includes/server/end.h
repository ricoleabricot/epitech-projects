/*
** end.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jul  2 13:03:38 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:09:58 2015 Pierrick Gicquelais
*/

#ifndef		END_H_
# define	END_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"

void		end_game(t_server *, t_client *, t_client *);

#endif		/* !END_H_ */
