/*
** team_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:33:34 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:33:44 2015 Pierrick Gicquelais
*/

#include	"server/team.h"

void		aff_teams(t_team *teams)
{
  teams = first_team(teams);
  while (teams)
    {
      printf("\t%s\n", teams->name);
      teams = teams->next;
    }
}

t_team		*find_team_by_name(t_team *teams, char *name)
{
  teams = first_team(teams);
  while (teams)
    {
      if (strcmp(teams->name, name) == 0)
	return (teams);
      teams = teams->next;
    }

  return (NULL);
}

bool		team_exists(t_team *teams, char *name)
{
  teams = first_team(teams);
  while (teams)
    {
      if (strcmp(teams->name, name) == 0)
	return (true);
      teams = teams->next;
    }
  return (false);
}
