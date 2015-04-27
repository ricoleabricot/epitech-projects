/*
** read_server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 14:40:40 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:28:34 2015 Pierrick Gicquelais
*/

#ifndef	        READ_SERVER_H_
# define	READ_SERVER_H_

# include	"server.h"

void		server_read(t_server *, int);
void		client_read(t_server *, int);

void		file_read(t_server *, int);
void		file_write(t_server *, int);

#endif		/* !READ_SERVER_H_ */
