/*
** miscellaneous_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar 19 16:32:19 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:26:45 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"getnextline.h"
#include	"split_string.h"
#include	"xopen.h"
#include	"xmalloc.h"
#include	"swrite.h"

void		unknown(t_server *serv, char *cmd)
{
  char		*buf;

  if (cmd[0] == 0)
    swrite(serv->cfd, "500 Try to be more inventive ;)\r\n");
  else
    {
      buf = xmalloc((strlen("500 Unknown Command: ") + \
		     strlen(cmd) + 3) * sizeof(char));
      memset(buf, 0, strlen("500 Unknown Command: ") + strlen(cmd) + 2);

      sprintf(buf, "500 Unknown Command: %s\r\n", cmd);
      swrite(serv->cfd, buf);
      free(buf);
    }
}

void		rm(t_server *serv, char *cmd)
{
  char		*filename;

  filename = split_string(cmd, ' ', 1);
  if (filename != NULL)
    {
      if (remove(filename) == -1)
	swrite(serv->cfd, "552 Impossible to remove the file\r\n");
      else
	swrite(serv->cfd, "257 File remove\r\n");
    }
  else
    swrite(serv->cfd, "501 You must enter a filename\r\n");
}

void		noop(t_server *serv, char *cmd)
{
  (void)cmd;
  swrite(serv->cfd, "220 Command okay\r\n");
}

void		quit(t_server *serv, char *cmd)
{
  (void)cmd;
  swrite(serv->cfd, "221 Bye.\r\n");
  close(serv->cfd);
}
