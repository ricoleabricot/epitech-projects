/*
** commands_client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:16:55 2015 Pierrick Gicquelais
** Last update Tue Jun 30 16:18:10 2015 Pierrick Gicquelais
*/

#ifndef		COMMANDS_CLIENT_H_
# define	COMMANDS_CLIENT_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdio.h>

# include	"server.h"
# include	"trim.h"
# include	"split_string.h"
# include	"commands_graphic.h"
# include	"incantation.h"
# include	"verbose.h"
# include	"swrite.h"

# define	FORWARD		"avance"
# define        LEFT		"gauche"
# define        RIGHT		"droite"
# define	SEE		"voir"
# define	INVENTORY	"inventaire"
# define	TAKE_OBJ       	"prend"
# define        PUT_OBJ		"pose"
# define        EXPULSE		"expulse"
# define        SPEAKING	"broadcast"
# define        SPELL		"incantation"
# define        FORK		"fork"
# define	CONNECT_NUMBER	"connect_nbr"

void		commands_client(t_server *, t_client *, char *);

void		forward(t_server *, t_client *, char *);
void	        left(t_server *, t_client *, char *);
void	        right(t_server *, t_client *, char *);
void	        see(t_server *, t_client *, char *);
void		inventory(t_server *, t_client *, char *);
void		take_obj(t_server *, t_client *, char *);
void	        put_obj(t_server *, t_client *, char *);
void	        expulse(t_server *, t_client *, char *);
void	        speaking(t_server *, t_client *, char *);
void	        spell(t_server *, t_client *, char *);
void	        fork_client(t_server *, t_client *, char *);
void	        connect_number(t_server *, t_client *, char *);

void		check_spell(t_server *, t_client *);

#endif		/* !COMMANDS_CLIENT_H_ */
