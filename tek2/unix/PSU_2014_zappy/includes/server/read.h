/*
** read.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 09:46:19 2015 Pierrick Gicquelais
** Last update Mon Jun 29 14:26:16 2015 Pierrick Gicquelais
*/

#ifndef		READ_H_
# define	READ_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"
# include	"connection.h"
# include	"commands_client.h"
# include	"verbose.h"
# include	"trim.h"
# include	"xaccept.h"
# include	"swrite.h"

t_client	*server_read(t_server *, int);
t_client	*client_read(t_server *, int);
t_client	*graphic_read(t_server *, int);
t_client	*verify_read(t_server *, int);

#endif		/* !READ_H_ */
