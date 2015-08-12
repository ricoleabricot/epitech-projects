/*
** run.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/includes/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:51:59 2015 Pierrick Gicquelais
** Last update Thu Jun 25 11:05:26 2015 Pierrick Gicquelais
*/

#ifndef		RUN_H_
# define	RUN_H_

# include	<stdbool.h>
# include	<signal.h>
# include	<sys/time.h>

# include	"server.h"
# include	"update.h"
# include	"verbose.h"
# include	"destroy.h"

void		run(t_server *);

#endif		/* RUN_H_ */
