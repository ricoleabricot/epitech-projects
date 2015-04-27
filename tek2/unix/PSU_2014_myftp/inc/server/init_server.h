/*
** init_server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:44:27 2015 Pierrick Gicquelais
** Last update Fri Mar 27 16:53:41 2015 Pierrick Gicquelais
*/

#ifndef		INIT_SERVER_H_
# define	INIT_SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>

# include	<arpa/inet.h>

# include	"server.h"

void		init(t_server *);
int		init_active(t_data *, char *, char *);
int		init_passive(t_data *);

#endif		/* !INIT_SERVER_H_ */
