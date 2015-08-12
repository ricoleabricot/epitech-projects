/*
** client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 10:27:25 2015 Pierrick Gicquelais
** Last update Fri Jul  3 10:11:28 2015 Pierrick Gicquelais
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdbool.h>

# include	"player.h"
# include	"xmalloc.h"

# define	FD_FREE		0
# define	FD_SERVER	1
# define	FD_CLIENT	2
# define	FD_GRAPHIC	3
# define	FD_VERIFY	4

typedef struct	s_server	t_server;
typedef struct	s_client	t_client;
typedef struct	s_player	t_player;

typedef		t_client *(*fct_r)(t_server *, int);
typedef		t_client *(*fct_w)(t_server *, t_client *, bool);

struct		s_client
{
  t_client	*prev;
  t_client	*next;

  int		socket;
  int		parent;
  char		*team;

  char		buf[512];
  int		buf_size;
  t_list	*messages;

  char		fd_type;
  fct_r		fct_read;
  fct_w		fct_write;

  t_player	*player;
};

t_client	*new_client(void);
t_client	*append_client(t_client *, int, char, fct_r);
t_client	*pop_client(t_client *, int);

t_client	*first_client(t_client *);
t_client	*last_client(t_client *);

t_client	*get_client_by_socket(t_client *, int);
t_client	*get_client_egg_by_team(t_client *, char *);

void		aff_clients(t_client *);
void		free_client(t_client *);
void		free_clients(t_client *);

int		clients_size(t_client *);
int		find_max_socket(t_client *);

t_client	*client_write(t_server *, t_client *, bool);

#endif		/* !CLIENT_H_ */
