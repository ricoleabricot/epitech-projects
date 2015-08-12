/*
** options.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 13:43:14 2015 Pierrick Gicquelais
** Last update Wed Jul  1 13:57:46 2015 Pierrick Gicquelais
*/

#ifndef		OPTIONS_H_
# define	OPTIONS_H_

# define	_GNU_SOURCE

# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>

# include	"verbose.h"
# include	"server.h"
# include	"serror.h"

# define	PORT		"-p"
# define	WIDTH		"-x"
# define	HEIGHT		"-y"
# define	TEAMS		"-n"
# define	MAX_CLIENTS	"-c"
# define	DELAY		"-t"
# define	BYPASS		"--bypass"
# define	VERBOSE		"--verbose"

void		get_options(t_server*, int, char **);
void		check_options(t_server *);

void		port(t_server *, int, char **, int *);
void	        map_width(t_server *, int, char **, int *);
void	        map_height(t_server *, int, char **, int *);
void	        teams(t_server *, int, char **, int *);
void		max_clients(t_server *, int, char **, int *);
void		delay(t_server *, int, char **, int *);
void		bypass(t_server *, int, char **, int *);
void		verbose(t_server *, int, char **, int *);

#endif		/* !OPTIONS_H_ */
