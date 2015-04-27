/*
** do_actions_client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Mar 21 15:40:19 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:02:59 2015 Pierrick Gicquelais
*/

#ifndef		DO_ACTIONS_CLIENT_H_
# define	DO_ACTIONS_CLIENT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>

# include	"client.h"

# define	STOR	("stor")
# define	PUT	("put")
# define	RETR	("retr")
# define	GET	("get")
# define	LIST	("list")
# define	LS	("ls")
# define	RLS	("rls")

void		do_actions(t_client *cli, char *cmd);

#endif		/* !DO_ACTIONS_CLIENT_H_ */
