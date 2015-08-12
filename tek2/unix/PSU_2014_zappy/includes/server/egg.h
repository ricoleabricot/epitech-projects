/*
** egg.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 29 18:17:35 2015 Pierrick Gicquelais
** Last update Mon Jun 29 18:50:16 2015 Pierrick Gicquelais
*/

#ifndef		EGG_H_
# define	EGG_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>

# include	"server.h"

t_client	*check_egg(t_server *, t_client *);

#endif		/* !EGG_H_ */
