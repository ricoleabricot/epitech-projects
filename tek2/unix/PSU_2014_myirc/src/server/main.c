/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 12:53:01 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:29:47 2015 Pierrick Gicquelais
*/

#include	"usage.h"
#include	"xmalloc.h"
#include	"init_server.h"
#include	"run_server.h"
#include	"destroy_server.h"

int	main(int argc, char **argv)
{
  t_server	*serv;

  if (argc != 2)
    usage(argv);

  serv = xmalloc(sizeof(t_server));
  serv->port = atoi(argv[1]);

  init(serv);
  run(serv);
  destroy(serv);

  return (0);
}
