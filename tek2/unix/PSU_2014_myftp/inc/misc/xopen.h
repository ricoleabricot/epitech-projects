/*
** xopen.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 15:16:10 2015 Pierrick Gicquelais
** Last update Tue Mar 17 15:17:19 2015 Pierrick Gicquelais
*/

#ifndef		XOPEN_H_
# define	XOPEN_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

int		xopen(const char *, int, mode_t);

#endif		/* !XOPEN_H_ */
