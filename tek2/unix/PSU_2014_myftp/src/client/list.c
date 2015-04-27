/*
** list.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 27 17:21:24 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:10:50 2015 Pierrick Gicquelais
*/

#include	"list.h"
#include	"protocol.h"
#include	"xfork.h"
#include	"swrite.h"

void		list(t_client *cli, char *cmd)
{
  char		ret[4096];
  char		buf[1];

  (void)cmd;
  pasv(cli);

  swrite(cli->fd, "LIST");
  memset(ret, 0, 4096);
  read(cli->fd, ret, 4096);
  write(1, ret, strlen(ret));
  while (read(cli->data->cfd, buf, 1) > 0)
    write(1, &buf[0], 1);
}

void		rlist(t_client *cli, char *cmd)
{
  pid_t		pid;

  (void)cmd;
  pid = xfork(cli->fd);
  if (pid == 0)
    execl("/bin/ls", "ls", "-l", NULL);
  else
    waitpid(pid, 0, WSTOPPED);
  swrite(cli->fd, "NOOP");
}
