/*
** lemipc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 20:47:22 2015 Pierrick Gicquelais
** Last update Sun Mar  8 12:43:38 2015 Pierrick Gicquelais
*/

#include	"lemipc.h"
#include	"xmalloc.h"
#include	"xftok.h"
#include	"xshm.h"
#include	"xsem.h"
#include	"xmsg.h"
#include	"error.h"

t_ipc		*ipc_initialization(char *name, unsigned char id)
{
  t_ipc		*ipc;
  char		*pwd;

  ipc = xmalloc(sizeof(t_ipc));
  ipc->id = id;
  ipc->name = strdup(name);
  ipc->position = 0;
  pwd = getenv("PWD");
  ipc->key = xftok(pwd, 0);
  ipc->shm_id = shmget(ipc->key, SHM_SIZE, SHM_R | SHM_W);
  ipc->sem_id = semget(ipc->key, 1, SHM_R | SHM_W);
  return (ipc);
}
