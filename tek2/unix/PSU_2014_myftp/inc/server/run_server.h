/*
** run_server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:45:16 2015 Pierrick Gicquelais
** Last update Wed Mar 18 15:39:37 2015 Pierrick Gicquelais
*/

#ifndef		RUN_SERVER_H_
# define	RUN_SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>

# include	<netinet/in.h>
# include	<arpa/inet.h>

# include	"server.h"

void		run(t_server *);

#endif		/* !RUN_SERVER_H_ */
