/*
** xmsg.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar  6 08:43:43 2015 Pierrick Gicquelais
** Last update Fri Mar  6 09:46:16 2015 Pierrick Gicquelais
*/

#ifndef		XMSG_H_
# define	XMSG_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# include	<sys/types.h>
# include	<sys/msg.h>

# include	"error.h"

int		xmsgget(key_t, int);
int		xmsgsnd(int, const void *, size_t, int);
int		xmsgctl(int, int, struct msqid_ds *);

#endif		/* !XMSG_H_ */
