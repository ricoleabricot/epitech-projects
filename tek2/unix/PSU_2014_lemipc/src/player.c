/*
** player.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 21:00:46 2015 Pierrick Gicquelais
** Last update Sun Mar  8 12:43:43 2015 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>

#include	"xshm.h"
#include	"xsem.h"
#include	"xmsg.h"
#include	"player.h"
#include	"game.h"
#include	"error.h"

void		first_player(t_ipc *ipc)
{
  ipc->shm_id = xshmget(ipc->key, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
  ipc->sem_id = xsemget(ipc->key, 1, IPC_CREAT | SHM_R | SHM_W);
  xsemctl(ipc->sem_id, 0, SETVAL, 1);
  ipc->map = xshmat(ipc->shm_id, NULL, 0);
  lock(ipc->sem_id);
  bzero(ipc->map, SHM_SIZE);
  unlock(ipc->sem_id);
  init_game(ipc);
  play_game(ipc);
}

void	        other_player(t_ipc *ipc)
{
  ipc->map = xshmat(ipc->shm_id, NULL, 0);
  init_game(ipc);
  play_game(ipc);
}
