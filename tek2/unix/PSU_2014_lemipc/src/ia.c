/*
** ia.c for lemipc in /home/barbu/lemipc/src
**
** Made by Cyril Labitte
** Login   <labitt_c@epitech.eu>
**
** Started on  Wed Mar 04 15:57:22 2015 Cyril Labitte
** Last update Sun Mar  8 20:01:32 2015 Pierrick Gicquelais
*/

#include	"ia.h"

int		get_end(int a)
{
  if ((a + 10) / 100 > a / 100)
    get_end(a - 1);
  else
    return (a + 10);
  return (a + 10);
}

int		find_enemy(t_ipc *ipc)
{
  int		pos_start;
  int		pos_end;
  int		position;
  int		i;

  position = ipc->position;
  pos_start = (((position / 100) * 100) - 500) + position - 5;
  pos_start = pos_start < 0 ? 0 : pos_start;
  pos_end = (((position / 100) * 100) + 500);
  pos_end = pos_end < SHM_SIZE ? SHM_SIZE : pos_end;
  i = pos_start;

  while (i < pos_end)
  {
    i = i - 10;
    while (i < get_end(position))
    {
      if (ipc->map[i] != 0 && ipc->map[i] != ipc->id && i != position)
	return (i);
      i++;
    }
    i += 100;
  }
  return (-1);
}

int		send_id(t_ipc *ipc, int *en_pos, int *msg_id, t_msg *message)
{
  if ((*en_pos = find_enemy(ipc)) != -1){
    bzero(message, sizeof(t_msg));
    message->type = 18;
    sprintf(message->text, "%d", *en_pos);
    if (msgsnd(*msg_id, message, sizeof(message), 0) == -1)
      my_error("Msgsnd Error");
    if (msgctl(*msg_id, IPC_RMID, NULL) == -1)
      my_error("Msgctl Error");
    return (go_to_enemy(*en_pos, ipc, 1));
  }
  else
  {
    ipc->position = random_move(ipc);
    bzero(message, sizeof(struct s_msg));
    message->type = 17;
    sprintf(message->text, "%c", 1);
    xmsgsnd(*msg_id, message, sizeof(message), 0);
    xmsgctl(*msg_id, IPC_RMID, NULL);
    return (ipc->position);
  }
}

int		ia(t_ipc *ipc)
{
  int		en_pos;
  int		msg_id;
  t_msg		message;

  en_pos = 0;
  if ((msg_id = msgget(ipc->key, SHM_R | SHM_W)) == -1)
  {
    msg_id = xmsgget(ipc->key, IPC_CREAT | SHM_R | SHM_W);
    if (msgrcv(msg_id, &message, sizeof(message), 18, 0) == -1 || \
	msgrcv(msg_id, &message, sizeof(message), 17, 0) == -1)
      my_error("msgrcv error");
    else if (message.type == 17)
    {
      ipc->position = random_move(ipc);
      return (ipc->position);
    }
    else if (message.type == 18)
      return (go_to_enemy(en_pos, ipc, 1));
  }
  return (send_id(ipc, &en_pos, &msg_id, &message));
}
