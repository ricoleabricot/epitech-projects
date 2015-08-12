/*
** team.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Jun 18 16:29:12 2015 Pierrick Gicquelais
** Last update Mon Jun 22 15:41:43 2015 Pierrick Gicquelais
*/

#ifndef		TEAM_H_
# define	TEAM_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdbool.h>

# include	"xmalloc.h"

typedef struct	s_team	t_team;
struct		s_team
{
  t_team	*prev;
  t_team	*next;

  char		*name;
  int		clients;
};

t_team		*new_team(void);
t_team		*append_team(t_team *, char *);

t_team		*first_team(t_team *);
t_team		*last_team(t_team *);

void		aff_teams(t_team *);
void		free_teams(t_team *);

t_team		*find_team_by_name(t_team *, char *);
bool		team_exists(t_team *, char *);

#endif		/* !TEAM_H_ */
