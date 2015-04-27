/*
** do_actions_server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 19:17:09 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:24:16 2015 Pierrick Gicquelais
*/

#ifndef	        DO_ACTIONS_SERVER_H_
# define	DO_ACTIONS_SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>
# include	<string.h>

# include	"server.h"

# define	USER		("user")
# define	PASS		("pass")
# define	SETUSER		("setuser")
# define	DISCONNECT	("disconnect")
# define	LS		("ls")
# define	LIST		("list")
# define	CD		("cd")
# define	CWD		("cwd")
# define	MKDIR		("mkdir")
# define	GET		("get")
# define	PUT		("put")
# define	RETR		("retr")
# define	STOR		("stor")
# define	DELE		("dele")
# define	RM		("rm")
# define	PWD		("pwd")
# define	HELP		("help")
# define	WHY		("?")
# define	TYPE		("type")
# define	PASV		("pasv")
# define	PORT		("port")
# define	NOOP		("noop")
# define	QUIT		("quit")

void	        do_actions(t_server *, char *);

#endif		/* !DO_ACTIONS_SERVER_H_ */
