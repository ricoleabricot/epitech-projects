/*
** xftok.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Feb 28 00:42:06 2015 Pierrick Gicquelais
** Last update Sat Feb 28 00:50:17 2015 Pierrick Gicquelais
*/

#ifndef		XFTOK_H_
# define	XFTOK_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/ipc.h>

key_t		xftok(const char *, int);

#endif		/* !XTOK_H_ */
