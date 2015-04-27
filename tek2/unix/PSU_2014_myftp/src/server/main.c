/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar  2 11:56:03 2015 Pierrick Gicquelais
** Last update Wed Mar 25 22:11:52 2015 Pierrick Gicquelais
*/

#include	"usage.h"
#include	"xmalloc.h"
#include	"init_server.h"
#include	"run_server.h"
#include	"destroy_server.h"

int		main(int argc, char **argv)
{
  t_server	*serv;

  if (argc != 2)
    usage(argv);

  serv = xmalloc(sizeof(t_server));
  serv->port = strdup(argv[1]);

  init(serv);
  run(serv);
  destroy(serv);

  return (EXIT_SUCCESS);
}
