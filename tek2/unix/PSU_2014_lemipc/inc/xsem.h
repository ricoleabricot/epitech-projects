/*
** xsem.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Feb 28 00:45:54 2015 Pierrick Gicquelais
** Last update Wed Mar  4 11:04:11 2015 Pierrick Gicquelais
*/

#ifndef		XSEM_H_
# define	XSEM_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/ipc.h>
# include	<sys/sem.h>

int		lock(int);
int		unlock(int);
int		xsemget(key_t, int, int);
int		xsemctl(int, int, int, int);
int		xsemop(int, struct sembuf *, unsigned);

#endif		/* !XSEM_H_ */
