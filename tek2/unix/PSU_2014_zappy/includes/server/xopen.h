/*
** xopen.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jul  1 12:05:34 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:08:34 2015 Pierrick Gicquelais
*/

#ifndef		XOPEN_H_
# define	XOPEN_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

# include	"merror.h"

int		xopen(const char *, int, mode_t);

#endif		/* !XOPEN_H_ */
