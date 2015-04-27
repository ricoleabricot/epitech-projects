/*
** session.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar 18 14:11:21 2015 Pierrick Gicquelais
** Last update Wed Mar 25 14:30:51 2015 Pierrick Gicquelais
*/

#ifndef	        SESSION_H_
# define	SESSION_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<limits.h>

# include	<sys/types.h>
# include	<sys/stat.h>

# include	"server.h"

void		connect_session(t_server *);
void		disconnect_session(t_server *);
void		create_session(t_server *, int, char *, char *);

#endif		/* !SESSION_H_ */
