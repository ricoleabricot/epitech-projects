/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar  2 11:56:03 2015 Pierrick Gicquelais
** Last update Tue Mar 24 23:49:01 2015 Pierrick Gicquelais
*/

#include	"usage.h"
#include	"xmalloc.h"
#include	"init_client.h"
#include	"run_client.h"
#include	"destroy_client.h"

#include	"getnextline.h"

int		main(int argc, char **argv)
{
  t_client	*cli;

  if (argc != 3)
    usage(argv);

  cli = xmalloc(sizeof(t_client));

  init(cli, argv);
  run(cli);
  destroy(cli);

  return (EXIT_SUCCESS);
}
