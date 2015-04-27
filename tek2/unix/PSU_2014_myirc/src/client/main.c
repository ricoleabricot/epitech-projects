/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 13:07:16 2015 Pierrick Gicquelais
** Last update Sat Apr 11 19:10:12 2015 Pierrick Gicquelais
*/

#include	"client.h"
#include	"init_client.h"
#include	"run_client.h"
#include	"destroy_client.h"
#include	"usage.h"
#include	"split_string.h"
#include	"xmalloc.h"

int		main(int argc, char **argv)
{
  t_client	*cli;

  if (argc > 2)
    usage(argv);

  cli = xmalloc(sizeof(t_client));
  first_init(cli);

  if (argc == 2)
    {
      cli->ip = split_string(argv[1], ':', 0);
      cli->port = split_string(argv[1], ':', 1);
    }

  init(cli);
  run(cli);
  destroy(cli);

  return (0);
}
