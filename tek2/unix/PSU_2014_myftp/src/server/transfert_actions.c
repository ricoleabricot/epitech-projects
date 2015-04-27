/*
** transfert_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 13:32:42 2015 Pierrick Gicquelais
** Last update Sat Mar 28 21:51:53 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"getnextline.h"
#include	"split_string.h"
#include	"xmalloc.h"
#include	"xopen.h"
#include	"swrite.h"

static void	upload(t_server *serv, char *file, char *filename)
{
  struct stat	st;
  char		buf[1];
  int		fd;

  if (filename == NULL)
    filename = strdup(file);

  fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0666);
  fstat(fd, &st);
  if (fd == -1 || !S_ISREG(st.st_mode))
    {
      while (read(serv->data->cfd, buf, 1) > 0);
      close(serv->data->cfd);
      swrite(serv->cfd, "552 Is a directory\r\n");
    }
  else
    {
      while (read(serv->data->cfd, buf, 1) > 0)
	write(fd, &buf[0], 1);
      close(fd);
      close(serv->data->cfd);
      swrite(serv->cfd, "226 ASCII Transfert completed\r\n");
    }
  free(filename);
}

void		put(t_server *serv, char *cmd)
{
  char		*file;
  char		*filename;
  char		ret[4096];

  swrite(serv->cfd, "150 ASCII data connection\r\n");

  file = split_string(cmd, ' ', 1);
  filename = split_string(cmd, ' ', 2);
  if (file != NULL)
    {
      upload(serv, file, filename);
      free(file);
    }
  else
    {
      memset(ret, 0, 4096);
      read(serv->cfd, ret, 4096);
      swrite(serv->cfd, ret);
    }
}

static void	download(t_server *serv, char *file)
{
  struct stat	st;
  char		buf[1];
  int		fd;

  fd = open(file, O_RDONLY);
  fstat(fd, &st);
  while (read(fd, buf, 1) > 0)
    write(serv->data->cfd, &buf[0], 1);
  close(fd);
  close(serv->data->cfd);
  swrite(serv->cfd, "226 ASCII Transfert completed\r\n");
}

void		get(t_server *serv, char *cmd)
{
  char		*file;

  swrite(serv->cfd, "150 ASCII data connection\r\n");

  file = split_string(cmd, ' ', 1);
  if (file != NULL)
    {
      download(serv, file);
      free(file);
    }
  else
    swrite(serv->cfd, "501 You must select a file to download\r\n");
}
