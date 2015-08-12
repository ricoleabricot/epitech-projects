/*
** xaccept.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 09:48:20 2015 Pierrick Gicquelais
** Last update Fri Jun 19 09:50:29 2015 Pierrick Gicquelais
*/

#ifndef		XACCEPT_H_
# define	XACCEPT_H_

# include	<sys/types.h>
# include	<sys/socket.h>

# include	"merror.h"

int		xaccept(int, struct sockaddr *, socklen_t *);

#endif		/* !XACCEPT_H_ */
