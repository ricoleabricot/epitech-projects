/*
** xaccept.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:35:42 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:51:24 2015 Pierrick Gicquelais
*/

#ifndef		XACCEPT_H_
# define	XACCEPT_H_

# include	<sys/types.h>
# include	<sys/socket.h>

int		xaccept(int, struct sockaddr *, socklen_t *);

#endif		/* !XACCEPT_H_ */
