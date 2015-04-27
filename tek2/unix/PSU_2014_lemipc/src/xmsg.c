/*
** xmsg.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar  6 08:41:40 2015 Pierrick Gicquelais
** Last update Fri Mar  6 09:44:34 2015 Pierrick Gicquelais
*/

#include	"xmsg.h"

int		xmsgget(key_t key, int msgflg)
{
  int		msg_id;

  if ((msg_id = msgget(key, msgflg)) == -1)
    perror("Msgget Error");
  return (msg_id);
}

int		xmsgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
  int		ret;

  if ((ret = msgsnd(msqid, msgp, msgsz, msgflg)) == -1)
    perror("Msgsnd Error");
  return (ret);
}

int		xmsgctl(int msqid, int cmd, struct msqid_ds *buf)
{
  int		ret;

  if ((ret = msgctl(msqid, cmd, buf)) == -1)
    perror("Msgctl Error");
  return (ret);
}
