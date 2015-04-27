/*
** xfork.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 17:37:34 2015 Pierrick Gicquelais
** Last update Fri Mar 13 17:41:09 2015 Pierrick Gicquelais
*/

#ifndef		XFORK_H_
# define	XFORK_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	<sys/types.h>
# include	<sys/wait.h>

pid_t		xfork(int);

#endif		/* !XFORK_H_ */
