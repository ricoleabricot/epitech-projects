/*
** init_client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:27:38 2015 Pierrick Gicquelais
** Last update Fri Mar 27 17:39:48 2015 Pierrick Gicquelais
*/

#ifndef		INIT_CLIENT_H_
# define	INIT_CLIENT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>
# include	<arpa/inet.h>

# include	"client.h"

void		init(t_client *, char **);
void		init_passive(t_data *, char *, char *);

#endif		/* !INIT_CLIENT_H_ */
