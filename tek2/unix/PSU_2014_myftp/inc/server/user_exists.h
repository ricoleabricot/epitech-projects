/*
** user_exists.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 16:31:05 2015 Pierrick Gicquelais
** Last update Tue Mar 17 16:31:52 2015 Pierrick Gicquelais
*/

#ifndef		USER_EXISTS_H_
# define	USER_EXISTS_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>

# include	"server.h"

bool		user_exists(t_server *, char *);

#endif		/* !USER_EXISTS_H_ */
