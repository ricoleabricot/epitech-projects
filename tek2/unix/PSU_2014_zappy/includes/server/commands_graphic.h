/*
** commands_graphic.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 12:10:15 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:46:45 2015 Pierrick Gicquelais
*/

#ifndef		COMMANDS_GRAPHIC_H_
# define	COMMANDS_GRAPHIC_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# include	"server.h"
# include	"trim.h"
# include	"split_string.h"
# include	"verbose.h"

# define	MAP_SIZE	"msz"
# define	CASE_CONTENT	"bct"
# define	MAP_CONTENT	"mct"
# define	TEAMS_NAME	"tna"
# define	PLAYER_POSITION	"ppo"
# define	PLAYER_LEVEL	"plv"
# define	PLAYER_INVENT	"pin"
# define	GET_DELAY	"sgt"
# define	SET_DELAY	"sst"

void		commands_graphic(t_server *, t_client *, char *);

void		graphic_connection(t_server *, int);
void		map_size(t_server *, t_client *, char *);
void	        case_content(t_server *, t_client *, char *);
void	        map_content(t_server *, t_client *, char *);
void	        teams_name(t_server *, t_client *, char *);
void	        player_position(t_server *, t_client *, char *);
void	        player_level(t_server *, t_client *, char *);
void	        player_inventory(t_server *, t_client *, char *);
void	        player_speaking(t_server *, t_client *, char *);
void	        player_put(t_server *, t_client *, int);
void	        player_take(t_server *, t_client *, int);
void	        player_expulse(t_server *, t_client *);
void	        player_dead(t_server *, t_client *);
void		server_message(t_server *, char *);
void	        get_delay(t_server *, t_client *, char *);
void	        set_delay(t_server *, t_client *, char *);

void		new_connection(t_server *, t_client *);

#endif		/* !COMMANDS_GRAPHIC_H_ */
