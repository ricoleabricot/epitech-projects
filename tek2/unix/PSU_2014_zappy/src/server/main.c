/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:41:35 2015 Pierrick Gicquelais
** Last update Tue Jun 23 14:47:25 2015 Pierrick Gicquelais
*/

#include	"server/usage.h"
#include	"server/xmalloc.h"

#include	"server/init.h"
#include	"server/generate.h"
#include	"server/run.h"
#include	"server/destroy.h"

int		main(int argc, char **argv)
{
  t_server	*server;

  if (argc < 2)
    {
      usage(argv);
      return -1;
    }

  server = xmalloc(sizeof(t_server));

  init(server, argc, argv);
  generate(server);
  run(server);
  destroy(server);

  return (0);
}
