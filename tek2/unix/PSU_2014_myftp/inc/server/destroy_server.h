/*
** destroy_server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:45:55 2015 Pierrick Gicquelais
** Last update Wed Mar 25 00:27:41 2015 Pierrick Gicquelais
*/

#ifndef		DESTROY_SERVER_H_
# define	DESTROY_SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"

void		destroy(t_server *);
void		destroy_data(t_data *);

#endif		/* !DESTROY_SERVER_H_ */
