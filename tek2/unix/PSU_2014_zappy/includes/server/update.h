/*
** update.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 25 11:04:19 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:05:18 2015 Pierrick Gicquelais
*/

#ifndef		UPDATE_H_
# define	UPDATE_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"
# include	"commands_client.h"
# include	"commands_graphic.h"
# include	"end.h"
# include	"swrite.h"

void		update(struct timeval *, struct timeval *, t_server *, t_client *);

#endif		/* !UPDATE_H_ */
