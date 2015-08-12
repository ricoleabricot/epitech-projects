/*
** usage.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:44:49 2015 Pierrick Gicquelais
** Last update Thu Jun 18 12:07:52 2015 Pierrick Gicquelais
*/

#include	"server/usage.h"

void		usage(char **argv)
{
  printf("%s: (-p port) (-x world_width) (-y world_height)", argv[0]);
  printf(" (-n team_name1 [...]) (-c max_clients) (-t delay)\n");
}
