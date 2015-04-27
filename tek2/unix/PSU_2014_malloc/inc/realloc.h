/*
** realloc.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_malloc/inc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  9 16:10:16 2015 Pierrick Gicquelais
** Last update Mon Feb  9 16:10:49 2015 Pierrick Gicquelais
*/

#ifndef		REALLOC_H_
# define	REALLOC_H_

# include	<stdlib.h>
# include	<unistd.h>

void		*realloc(void *ptr, size_t size);
void		*set_alloc(void *ptr, size_t size, size_t old_size);

#endif		/* !REALLOC_H_ */
