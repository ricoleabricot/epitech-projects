/*
** xgetprotobyname.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:23:51 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:54:46 2015 Pierrick Gicquelais
*/

#ifndef			XGETPROTOBYNAME_H_
# define		XGETPROTOBYNAME_H_

# include		<netdb.h>

# include		"merror.h"

struct	protoent	*xgetprotobyname(const char *name);

#endif			/* !XGETPROTOBYNAME_H_ */
