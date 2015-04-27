/*
** send.c for minitalk in /home/gicque_p/local/unix/PSU_2013_minitalk/src_client
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Mar 11 13:51:53 2014 Pierrick Gicquelais
** Last update Thu Mar 20 08:54:51 2014 Pierrick Gicquelais
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"minitalk.h"

void		put_msg(int server_pid, unsigned char msg)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      usleep(100);
      if (msg % 2 == 0)
	kill(server_pid, SIGUSR2);
      else
        kill(server_pid, SIGUSR1);
      i++;
      msg /= 2;
    }
}

void		my_send(int server_pid, char *msg)
{
  int		i;

  i = 0;
  while (msg[i])
    {
      put_msg(server_pid, msg[i]);
      i++;
    }
  put_msg(server_pid, '\n');
}

void		my_time(int server_pid)
{
  char		*date;
  int		i;

  i = 0;
  if ((date = malloc(29 * sizeof(char))) == NULL)
    my_error("Error 3: Error with a memory allocation", 3);
  date[0] = '[';
  date = my_strcpy(date, 1);
  date[25] = ']';
  date[26] = ':';
  date[27] = ' ';
  date[28] = '\0';
  while (date[i])
    {
      put_msg(server_pid, date[i]);
      i++;
    }
  free(date);
}
