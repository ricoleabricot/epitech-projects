/*
** delay.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/option
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:39:20 2015 Pierrick Gicquelais
** Last update Sat Jun 27 20:39:50 2015 Pierrick Gicquelais
*/

#include	"server/options.h"

void		delay(t_server *server, int argc, char **argv, int *i)
{
  (void)argc;

  (*i)++;
  if (argv[(*i)] != NULL)
    server->delay = atoi(argv[(*i)]);
  else
    serror("You must enter a delay value");
}
