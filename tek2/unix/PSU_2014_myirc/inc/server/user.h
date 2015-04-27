/*
** user.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:49:32 2015 Pierrick Gicquelais
** Last update Wed Apr 15 15:05:54 2015 Pierrick Gicquelais
*/

#ifndef		USER_H_
# define	USER_H_

# define	_GNU_SOURCE
# include	<string.h>

# include	"server.h"

t_user		*new_user(void);
t_user		*append_user(t_user *, int, char *);
t_user		*first_user(t_user *);
t_user		*last_user(t_user *);
t_user		*pop_user(t_user *, int);
t_user		*get_user_by_fd(t_user *, int);
t_user		*get_user_by_nick(t_user *, char *);

char		*get_users_name(t_user *, t_channel *);

bool		user_exists(t_user *, char *);
bool		channel_is_empty(t_user *, char *);

void		aff_users(t_user *, char *, int);
void		free_user(t_user *);
void		free_users(t_user *);

#endif		/* !USER_H_ */
