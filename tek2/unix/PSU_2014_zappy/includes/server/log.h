/*
** log.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jul  1 11:53:20 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:34:30 2015 Pierrick Gicquelais
*/

#ifndef		LOG_H_
# define	LOG_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<dirent.h>
# include	<time.h>

# include	<sys/types.h>
# include	<sys/stat.h>

# include	"xopen.h"
# include	"swrite.h"

void		logs(char *, char *);

#endif		/* !LOG_H_ */
