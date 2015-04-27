/*
** transfert.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 20 19:05:38 2015 Pierrick Gicquelais
** Last update Sat Mar 21 17:29:39 2015 Pierrick Gicquelais
*/

#ifndef		TRANSFERT_H_
# define	TRANSFERT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>

# include	<sys/types.h>
# include	<sys/stat.h>

# include	"client.h"

void		upload(t_client *, char *);
void		download(t_client *, char *);

#endif		/* !TRANSFERT_H_ */
