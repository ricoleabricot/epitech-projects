/*
** authentication.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 15:17:53 2015 Pierrick Gicquelais
** Last update Wed Mar 25 14:17:08 2015 Pierrick Gicquelais
*/

#ifndef		AUTHENTICATION_H_
# define	AUTHENTICATION_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdbool.h>

# include	"server.h"

void		find_account(t_server *, char *);
void		authentication(t_server *, char *);
bool		check_value(t_server *, char *, char *);

#endif		/* !AUTHENTICATION_H_ */
