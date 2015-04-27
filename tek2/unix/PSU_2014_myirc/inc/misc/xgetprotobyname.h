/*
** xgetprotobyname.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:58:43 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:58:44 2015 Pierrick Gicquelais
*/

#ifndef		XGETPROTOBYNAME_H_
# define	XGETPROTOBYNAME_H_

# include	<netdb.h>

struct protoent *xgetprotobyname(const char *);

#endif		/* !XGETPROTOBYNAME_H_ */
