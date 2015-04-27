/*
** xgetprotobyname.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:35:38 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:49:34 2015 Pierrick Gicquelais
*/

#ifndef		XGETPROTOBYNAME_H_
# define	XGETPROTOBYNAME_H_

# include	<netdb.h>

struct protoent *xgetprotobyname(const char *);

#endif		/* !XGETPROTOBYNAME_H_ */
