/*
** malloc.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/inc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 16:08:25 2015 Pierrick Gicquelais
** Last update Mon Feb  9 16:11:02 2015 Pierrick Gicquelais
*/

#ifndef		MALLOC_H_
# define	MALLOC_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<errno.h>
# include	"heap.h"

void		*my_malloc(size_t size);
void		*find(size_t size);

#endif		/* !MALLOC_H_ */
