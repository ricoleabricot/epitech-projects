/*
** verbose.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/option
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:38:05 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:38:30 2015 Pierrick Gicquelais
*/

#include	"server/options.h"

void		verbose(t_server *server, int argc, char **argv, int *i)
{
  (void)argc;
  (void)argv;
  (void)i;

  server->verbose = true;
}
