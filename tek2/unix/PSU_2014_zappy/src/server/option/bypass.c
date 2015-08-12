/*
** bypass.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/option
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:38:38 2015 Pierrick Gicquelais
** Last update Wed Jul  1 13:58:12 2015 Pierrick Gicquelais
*/

#include	"server/options.h"

void		bypass(t_server *server, int argc, char **argv, int *i)
{
  (void)argc;
  (void)argv;
  (void)i;

  server->port = 8080;
  server->width = 100;
  server->height = 100;
  server->teams = append_team(server->teams, "Team1");
  server->teams = append_team(server->teams, "Team2");
  server->max_clients = 10;
  server->delay = 100;
  server->verbose = true;
}
