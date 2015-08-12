/*
** buffer.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jul  2 12:36:14 2015 Pierrick Gicquelais
** Last update Thu Jul  2 12:36:59 2015 Pierrick Gicquelais
*/

#ifndef		BUFFER_H_
# define	BUFFER_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"
# include	"split_string.h"

t_client	*buffering(t_server *, char *, int);

#endif		/* !BUFFER_H_ */
