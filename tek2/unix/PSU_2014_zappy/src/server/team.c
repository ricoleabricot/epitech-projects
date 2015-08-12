/*
** team.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 15:55:47 2015 Pierrick Gicquelais
** Last update Wed Jun 24 10:17:37 2015 Pierrick Gicquelais
*/

#include	"server/team.h"

t_team		*new_team(void)
{
  t_team	*new;

  new = xmalloc(sizeof(t_team));

  new->prev = NULL;
  new->next = NULL;

  new->name = NULL;
  new->clients = 0;

  return (new);
}

t_team		*append_team(t_team *old, char *name)
{
  t_team	*new;

  new = new_team();
  if ((old = last_team(old)) != NULL)
    old->next = new;

  new->prev = old;
  new->next = NULL;

  new->name = strdup(name);

  return (new);
}

t_team		*first_team(t_team *teams)
{
  if (teams != NULL)
    while (teams->prev != NULL)
      teams = teams->prev;
  return (teams);
}

t_team		*last_team(t_team *teams)
{
  if (teams != NULL)
    while (teams->next != NULL)
      teams = teams->next;
  return (teams);
}

void		free_teams(t_team *teams)
{
  t_team	*tmp;

  teams = first_team(teams);
  while (teams)
    {
      tmp = teams;
      teams = teams->next;

      if (tmp->name != NULL)
	free(tmp->name);

      free(tmp);
    }
}
