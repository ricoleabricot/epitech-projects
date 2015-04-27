/*
** getnextline.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 17:50:52 2015 Pierrick Gicquelais
** Last update Fri Mar 13 18:10:50 2015 Pierrick Gicquelais
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
