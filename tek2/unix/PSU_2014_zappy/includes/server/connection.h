/*
** connection.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 14:30:07 2015 Pierrick Gicquelais
** Last update Thu Jul  2 12:38:54 2015 Pierrick Gicquelais
*/

#ifndef		CONNECTION_H_
# define	CONNECTION_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# include	"server.h"
# include	"buffer.h"
# include	"egg.h"
# include	"read.h"
# include	"commands_graphic.h"
# include	"trim.h"

t_client	*check_connection(t_server *, int);

#endif		/* !CONNECTION_H_ */
