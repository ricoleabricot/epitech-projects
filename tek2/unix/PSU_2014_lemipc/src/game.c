/*
** game.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar  3 09:36:07 2015 Pierrick Gicquelais
** Last update Sun Mar  8 20:01:04 2015 Pierrick Gicquelais
*/

#include		"game.h"
#include		"algorithm.h"
#include		"xshm.h"
#include		"xsem.h"
#include		"xmsg.h"

void			init_game(t_ipc *ipc)
{
  ipc->position = rand() % SHM_SIZE;
  while (ipc->map[ipc->position] != 0)
    ipc->position = rand() % SHM_SIZE;
  lock(ipc->sem_id);
  ipc->map[ipc->position] = ipc->id;
  unlock(ipc->sem_id);
  usleep(5000);
}

void			play_game(t_ipc *ipc)
{
  struct shmid_ds	buf;

  while (win_game(ipc) != 1)
    {
      lock(ipc->sem_id);
      ipc->map[ipc->position] = 0;
      unlock(ipc->sem_id);
      ipc->position = find_new_position(ipc->map, ipc->id, ipc->position);
      lock(ipc->sem_id);
      ipc->map[ipc->position] = ipc->id;
      unlock(ipc->sem_id);
      usleep(2000);
    }

  xshmctl(ipc->shm_id, IPC_STAT, &buf);
  if (buf.shm_nattch < 3)
    end_game(ipc);
}

int			win_game(t_ipc *ipc)
{
  int			i;
  int			tab[4];
  int			cpt;

  i = 0;
  cpt = 0;
  while (i < SHM_SIZE)
    {
      if (ipc->map[i] != 0)
	{
	  if (ipc->map[i] != tab[0] && ipc->map[i] != tab[1] && \
	      ipc->map[i] != tab[2] && ipc->map[i] != tab[3])
	    {
	      tab[cpt] = ipc->map[i];
	      cpt++;
	    }
	}
      i++;
    }

  return (cpt);
}

void			end_game(t_ipc *ipc)
{
  xshmctl(ipc->shm_id, IPC_RMID, NULL);
  xsemctl(ipc->sem_id, 0, IPC_RMID, 0);
  printf("Team '%s' win the game !\n", ipc->name);
  free(ipc->name);
  free(ipc);
}
