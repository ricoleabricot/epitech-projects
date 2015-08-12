/*
** xbind.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:14:28 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:26:35 2015 Pierrick Gicquelais
*/

#ifndef		XBIND_H_
# define	XBIND_H_

# include	<sys/types.h>
# include	<sys/socket.h>

# include	"merror.h"

int		xbind(int, const struct sockaddr *, socklen_t);

#endif		/* !XBIND_H_ */
