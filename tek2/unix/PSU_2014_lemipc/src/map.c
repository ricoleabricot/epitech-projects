/*
** map.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 23:23:50 2015 Pierrick Gicquelais
** Last update Sat Feb 28 00:45:18 2015 Pierrick Gicquelais
*/

#include	"lemipc.h"
#include	"xshm.h"

char		**get_map(t_ipc *ipc)
{
  char		**arena;

  ipc->shm_id = shmget(ipc->key, 100 * 100, SHM_R | SHM_W);
  if (ipc->shm_id == -1)
    {
      ipc->shm_id = xshmget(ipc->key, 100 * 100, IPC_CREAT | SHM_R | SHM_W);
      arena = xshmat(ipc->shm_id, NULL, SHM_R | SHM_W);
    }
  else
    {
      arena = xshmat(ipc->shm_id, NULL, SHM_R | SHM_W);
    }

  return (arena);
}
