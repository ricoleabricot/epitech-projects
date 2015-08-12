/*
** destroy.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:48:33 2015 Pierrick Gicquelais
** Last update Wed Jul  1 13:53:45 2015 Pierrick Gicquelais
*/

#include	"server/destroy.h"

void		destroy(t_server *server)
{
  free_teams(server->teams);
  free_clients(server->clients);
  free_map(server->map);
  free(server);

  printf("Bye.\n");
}
