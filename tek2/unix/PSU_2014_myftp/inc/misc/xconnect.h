/*
** xconnect.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 16:40:33 2015 Pierrick Gicquelais
** Last update Fri Mar 13 16:41:21 2015 Pierrick Gicquelais
*/

#ifndef		XCONNECT_H_
# define	XCONNECT_H_

#include	<sys/types.h>
#include	<sys/socket.h>

int		xconnect(int, const struct sockaddr *, socklen_t);

#endif		/* !XCONNECT_H_ */
