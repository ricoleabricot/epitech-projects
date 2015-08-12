/*
** init.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/includes/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:51:26 2015 Pierrick Gicquelais
** Last update Wed Jun 24 11:54:14 2015 Christian Boisson
*/

#ifndef		INIT_H_
# define	INIT_H_

# include	"server.h"
# include	"options.h"
# include	"read.h"
# include	"list.h"
# include	"case.h"

# include	"xgetprotobyname.h"
# include	"xsocket.h"
# include	"xbind.h"
# include	"xlisten.h"

void		init(t_server *, int, char **);

#endif		/* INIT_H_ */
