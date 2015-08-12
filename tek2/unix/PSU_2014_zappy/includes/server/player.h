/*
** player.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 17:14:50 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:59:49 2015 Pierrick Gicquelais
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	<stdlib.h>
# include	<unistd.h>

# include	"list.h"
# include	"case.h"
# include	"resources.h"
# include	"client.h"

enum		e_oritentation
  {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
  };

typedef struct	s_server	t_server;
typedef struct	s_client	t_client;
typedef struct	s_player	t_player;
struct		s_player
{
  int		id;
  char		*team;
  int		level;
  int		delay_action;
  int		delay_food;
  int		x;
  int		y;
  int		orientation;

  int		resources[7];
  t_list	*actions;
  bool		spell;

  t_client	*client;
};

void		create_player(t_server *server, t_client *client);
void		create_player_at_pos(t_server *server, t_client *client, \
				     int x, int y);
void		add_player(t_server *server, t_player *player, int w, int h);
void		add_player_to_pos(t_server *server, t_player *player, \
				  int x, int y);
void		init_player(t_player *player, int id, char *team);
void		free_list_player(t_list *player);
void		free_player(t_player *player);

#endif		/* !PLAYER_H_ */
