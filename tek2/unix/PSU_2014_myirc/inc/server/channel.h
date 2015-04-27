/*
** channel.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:29:45 2015 Pierrick Gicquelais
** Last update Thu Apr  9 13:23:56 2015 Pierrick Gicquelais
*/

#ifndef		CHANNEL_H_
# define	CHANNEL_H_

# define	_GNU_SOURCE
# include	<string.h>

# include	"server.h"

t_channel	*new_channel(void);
t_channel	*append_channel(t_channel *, char *);
t_channel	*first_channel(t_channel *);
t_channel	*last_channel(t_channel *);
t_channel	*pop_channel(t_channel *, char *);
t_channel	*get_channel_by_name(t_channel *, char *);

bool		channel_exists(t_channel *, char *);
bool		is_invite(t_channel *, char *);

void		aff_channels(t_channel *, char *, int);
void		free_channel(t_channel *);
void		free_channels(t_channel *);

#endif		/* !CHANNEL_H_ */
