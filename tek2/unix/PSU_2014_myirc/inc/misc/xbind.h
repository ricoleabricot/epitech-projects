/*
** xbind.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:58:17 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:58:17 2015 Pierrick Gicquelais
*/

#ifndef		XBIND_H_
# define	XBIND_H_

# include	<sys/types.h>
# include	<sys/socket.h>

int		xbind(int, const struct sockaddr *, socklen_t);

#endif		/* !XBIND_H_ */
