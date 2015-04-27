/*
** xshm.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Feb 28 00:44:00 2015 Pierrick Gicquelais
** Last update Mon Mar  2 13:44:20 2015 Pierrick Gicquelais
*/

#ifndef		XSHM_H_
# define	XSHM_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>

int		xshmget(key_t, size_t, int);
void		xshmctl(int, int, struct shmid_ds *);
void		*xshmat(int, const void *, int);
int		xshmdt(const void *);

#endif		/* !XSHM_H_ */
