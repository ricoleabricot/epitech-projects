/*
** xaccept.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:58:11 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:58:12 2015 Pierrick Gicquelais
*/

#ifndef		XACCEPT_H_
# define	XACCEPT_H_

# include	<sys/types.h>
# include	<sys/socket.h>

int		xaccept(int, struct sockaddr *, socklen_t *);

#endif		/* !XACCEPT_H_ */
