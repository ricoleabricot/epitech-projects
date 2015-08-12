/*
** teams.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/option
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:40:38 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:41:14 2015 Pierrick Gicquelais
*/

#include	"server/options.h"

void		teams(t_server *server, int argc, char **argv, int *i)
{
  (void)server;
  (*i)++;
  while ((*i) < argc)
    {
      if (argv[(*i)][0] == '-')
        {
	  (*i)--;
	  break;
	}

      if (strcmp(argv[(*i)], "GRAPHIC") == 0)
        serror("You can't enter GRAPHIC team name");
      else if (team_exists(server->teams, argv[(*i)]))
	serror("You can't enter twice the same team name");
      server->teams = append_team(server->teams, argv[(*i)]);
      (*i)++;
    }
}
