/*
** xshmget.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 22:58:16 2015 Pierrick Gicquelais
** Last update Mon Mar  2 13:51:13 2015 Pierrick Gicquelais
*/

#include	"xshm.h"
#include	"error.h"

int		xshmget(key_t key, size_t size, int shmflg)
{
  int		shmid;

  if ((shmid = shmget(key, size, shmflg)) == -1)
    my_error("Shmget Error");
  return (shmid);
}

void		xshmctl(int shmid, int cmd, struct shmid_ds *buf)
{
  if (shmctl(shmid, cmd, buf) == -1)
    my_error("Shmctl Error");
}

void		*xshmat(int shmid, const void *shmaddr, int shmflg)
{
  void		*ret;

  if ((ret = shmat(shmid, shmaddr, shmflg)) == (void *)-1)
    my_error("Shmat Error");
  return (ret);
}

int		xshmdt(const void *data)
{
  int		ret;

  if ((ret = shmdt(data)) == -1)
    my_error("Shmdt Error");
  return (ret);
}
