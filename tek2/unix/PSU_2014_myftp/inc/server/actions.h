/*
** actions.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 13:33:20 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:24:34 2015 Pierrick Gicquelais
*/

#ifndef		ACTIONS_H_
# define	ACTIONS_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<limits.h>
# include	<errno.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<dirent.h>

# include	"server.h"

void		user(t_server *, char *);
void		pass(t_server *, char *);
void		setuser(t_server *, char *);
void		disconnect(t_server *, char *);
void		ls(t_server *, char *);
void		cd(t_server *, char *);
void		pwd(t_server *, char *);
void	        makedir(t_server *, char *);
void		put(t_server *, char *);
void		get(t_server *, char *);
void	        rm(t_server *, char *);
void		help(t_server *, char *);
void		quit(t_server *, char *);
void		type(t_server *, char *);
void		pasv(t_server *, char *);
void		port(t_server *, char *);
void		noop(t_server *, char *);
void		unknown(t_server *, char *);

#endif		/* !ACTIONS_H_ */
