/*
** lemipc.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb 25 19:55:35 2015 Pierrick Gicquelais
** Last update Fri Mar  6 16:17:40 2015 Pierrick Gicquelais
*/

#ifndef		LEMIPC_H_
# define	LEMIPC_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>

# define	SHM_SIZE	(10000)

typedef struct	s_ipc	t_ipc;
typedef struct	s_msg	t_msg;

struct		s_ipc
{
  unsigned char	id;
  char		*name;
  int		position;

  unsigned char	*map;

  key_t		key;
  int		shm_id;
  int		sem_id;
  int		msg_id;
};

struct		s_msg
{
  long		type;
  char		text[1];
};

t_ipc		*ipc_initialization(char *, unsigned char);

#endif		/* !LEMIPC_H_ */
