/*
** heap.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/inc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 16:08:02 2015 Pierrick Gicquelais
** Last update Wed Feb 11 14:45:08 2015 Christian Boisson
*/

#ifndef		HEAP_H_
# define	HEAP_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<errno.h>
# define	HEAP_SIZE(val) (((val) + 7) & ~7)

size_t		*heap_start(void);
size_t		*heap_end(void);

#endif		/* !HEAP_H_ */
