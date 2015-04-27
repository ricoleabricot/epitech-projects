/*
** xsem.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 23:47:35 2015 Pierrick Gicquelais
** Last update Wed Mar  4 11:12:10 2015 Pierrick Gicquelais
*/

#include	"xsem.h"
#include	"error.h"

int		lock(int semid)
{
  struct sembuf	op;

  op.sem_num = 0;
  op.sem_flg = 0;
  op.sem_op = -1;

  return (xsemop(semid, &op, 1));
}

int		unlock(int semid)
{
  struct sembuf	op;

  op.sem_num = 0;
  op.sem_flg = 0;
  op.sem_op = 1;

  return (xsemop(semid, &op, 1));
}

int		xsemget(key_t key, int nsems, int semflg)
{
  int		sem_id;

  if ((sem_id = semget(key, nsems, semflg)) == -1)
    my_error("Semget Error");
  return (sem_id);
}

int		xsemctl(int semid, int semnum, int cmd, int semval)
{
  int		ret;

  if ((ret = semctl(semid, semnum, cmd, semval)) == -1)
    my_error("Semctl Error");
  return (ret);
}

int		xsemop(int semid, struct sembuf *sops, unsigned nsops)
{
  int		ret;

  if ((ret = semop(semid, sops, nsops)) == -1)
    my_error("Semop Error");
  return (ret);
}
