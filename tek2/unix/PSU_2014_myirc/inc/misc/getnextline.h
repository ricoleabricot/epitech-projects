/*
** getnextline.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/inc/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:57:02 2015 Pierrick Gicquelais
** Last update Sat Apr  4 12:57:03 2015 Pierrick Gicquelais
*/

#ifndef		GETNEXTLINE_H_
# define	GETNEXTLINE_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>

# define	BUF_SIZE        1

typedef struct	s_str	t_str;
struct		s_str
{
  t_str		*prev;
  t_str		*next;
  char		*str;
};

char		*getnextline(const int);

#endif		/* !GETNEXTLINE_H_ */
