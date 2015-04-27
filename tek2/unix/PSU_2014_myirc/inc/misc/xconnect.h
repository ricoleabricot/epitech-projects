/*
** xconnect.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:58:27 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:58:28 2015 Pierrick Gicquelais
*/

#ifndef		XCONNECT_H_
# define	XCONNECT_H_

#include	<sys/types.h>
#include	<sys/socket.h>

int		xconnect(int, const struct sockaddr *, socklen_t);

#endif		/* !XCONNECT_H_ */
