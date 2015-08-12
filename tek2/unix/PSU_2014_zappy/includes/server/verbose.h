/*
** verbose.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 13:29:01 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:37:21 2015 Pierrick Gicquelais
*/

#ifndef		VERBOSE_H_
# define	VERBOSE_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<stdio.h>

# include	"server.h"
# include	"log.h"
# include	"trim.h"

void		aff_server(t_server *);
void		verbose_connection(t_client *);
void		verbose_read(t_client *);
void		verbose_write(t_client *, char *);

#endif		/* !VERBOSE_H_ */
