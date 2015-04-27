/*
** list.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 27 17:35:44 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:02:49 2015 Pierrick Gicquelais
*/

#ifndef		LIST_H_
# define	LIST_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# include	"client.h"

void		list(t_client *, char *);
void		rlist(t_client *, char *);

#endif		/* !LIST_H_ */
