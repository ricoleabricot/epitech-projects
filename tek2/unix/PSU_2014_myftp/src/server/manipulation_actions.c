/*
** manipulation_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 13:31:32 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:26:35 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"split_string.h"
#include	"init_server.h"
#include	"destroy_server.h"
#include	"xchdir.h"
#include	"xgetcwd.h"
#include	"xopen.h"
#include	"xfork.h"
#include	"xmalloc.h"
#include	"swrite.h"

void		ls(t_server *serv, char *cmd)
{
  int		oldfd;
  pid_t		pid;

  (void)cmd;
  swrite(serv->cfd, "150 ASCII data connection\r\n");

  oldfd = dup(1);
  dup2(serv->data->cfd, 1);
  pid = xfork(serv->data->cfd);
  if (pid == 0)
    execl("/bin/ls", "ls", "-l", NULL);
  else
    waitpid(pid, 0, WSTOPPED);
  dup2(oldfd, 1);
  close(serv->data->cfd);

  swrite(serv->cfd, "226 ASCII Transfert completed\r\n");
}

static void	changedir(t_server *serv, char *path)
{
  char		*rpath;

  rpath = xmalloc(PATH_MAX);
  if (realpath(path, rpath) == NULL)
    swrite(serv->cfd, "552 No such file or directory\r\n");
  else
    {
      if (strncmp(serv->root, rpath, strlen(serv->root)) != 0)
	swrite(serv->cfd, "552 Can't access lower than root folder\r\n");
      else
	{
	  xchdir(path);
	  swrite(serv->cfd, "250 Requested file action okay, completed.\r\n");
	}
      free(rpath);
    }
}

void		cd(t_server *serv, char *cmd)
{
  char		*path;
  char		*newpath;

  path = split_string(cmd, ' ', 1);
  if (path != NULL)
    {
      if (path[0] == '/')
	{
	  newpath = xmalloc(PATH_MAX);
	  sprintf(newpath, "%s%s", serv->root, path);
	  changedir(serv, newpath);
	  free(newpath);
	}
      else
	changedir(serv, path);
      free(path);
    }
  else
    changedir(serv, serv->root);
}

void		pwd(t_server *serv, char *cmd)
{
  char		*path;
  char		*shortpath;
  int		i;
  int		j;

  (void)cmd;
  i = 0;
  j = 0;
  path = NULL;
  path = xgetcwd(".", path);
  shortpath = xmalloc(PATH_MAX);
  memset(shortpath, 0, PATH_MAX);
  while (path[i])
    {
      if (path[i] != serv->root[i])
	shortpath[j++] = path[i];
      i++;
    }
  if (shortpath[0] == 0)
    shortpath[0] = '/';
  memset(path, 0, PATH_MAX);
  sprintf(path, "257 %s\r\n", shortpath);
  swrite(serv->cfd, path);
  free(path);
  free(shortpath);
}

void		makedir(t_server *serv, char *cmd)
{
  char		*dir;

  dir = split_string(cmd, ' ', 1);
  if (dir != NULL)
    {
      if (mkdir(dir, 0775) == -1)
	swrite(serv->cfd, "552 Folder exists\r\n");
      else
	swrite(serv->cfd, "257 Folder create\r\n");
    }
  else
    swrite(serv->cfd, "501 You must enter a folder name\r\n");
}
