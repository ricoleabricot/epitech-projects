/*
** transfert.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 20 19:04:21 2015 Pierrick Gicquelais
** Last update Sat Mar 28 21:54:10 2015 Pierrick Gicquelais
*/

#include	"transfert.h"
#include	"protocol.h"
#include	"split_string.h"
#include	"getnextline.h"
#include	"xopen.h"
#include	"xmalloc.h"
#include	"swrite.h"

void		upload(t_client *cli, char *cmd)
{
  char		ret[4096];
  char		*file;
  char		buf[1];
  int		fd;

  pasv(cli);
  swrite(cli->fd, cmd);
  memset(ret, 0, 4096);
  read(cli->fd, ret, 4096);
  write(1, ret, strlen(ret));

  file = split_string(cmd, ' ', 1);
  if (file != NULL)
    {
      fd = open(file, O_RDONLY);
      if (fd != 1)
	while (read(fd, buf, 1) > 0)
	  write(cli->data->cfd, &buf[0], 1);
      close(fd);
      close(cli->data->cfd);
      free(file);
    }
  else
    swrite(cli->fd, "501 You must enter a file to upload\r\n");
}

static void	get_download(t_client *cli, char *file, char *filename)
{
  struct stat	st;
  char		buf[1];
  int		fd;

  if (filename == NULL)
    filename = strdup(file);

  fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0666);
  fstat(fd, &st);
  if (fd != -1 && S_ISREG(st.st_mode))
    {
      while (read(cli->data->cfd, buf, 1) > 0)
	write(fd, &buf[0], 1);
      close(cli->data->cfd);
      close(fd);
    }
  else
    {
      while (read(cli->data->cfd, buf, 1) > 0);
      close(cli->data->cfd);
      perror(NULL);
    }

  free(filename);
  free(file);
}

void		download(t_client *cli, char *cmd)
{
  char		ret[4096];
  char		*file;
  char		*filename;

  pasv(cli);
  swrite(cli->fd, cmd);
  memset(ret, 0, 4096);
  read(cli->fd, ret, 4096);
  write(1, ret, strlen(ret));

  file = split_string(cmd, ' ', 1);
  filename = split_string(cmd, ' ', 2);
  if (file != NULL)
    get_download(cli, file, filename);
  else
    write(1, ret, strlen(ret));
}
