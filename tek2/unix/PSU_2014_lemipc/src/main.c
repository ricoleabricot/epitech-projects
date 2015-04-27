/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb 25 19:57:53 2015 Pierrick Gicquelais
** Last update Fri Mar  6 09:32:13 2015 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<time.h>

#include	"lemipc.h"
#include	"player.h"
#include	"usage.h"

int		main(int argc, char **argv)
{
  t_ipc		*ipc;

  if (argc != 3)
    usage(argv);

  srand(time(NULL));
  ipc = ipc_initialization(argv[1], atoi(argv[2]));

  if (ipc->shm_id == -1)
    first_player(ipc);
  else
    other_player(ipc);

  return (0);
}
