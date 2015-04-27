/*
** read_file.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 18:35:31 2015 Pierrick Gicquelais
** Last update Wed Apr 15 21:43:37 2015 Pierrick Gicquelais
*/

#include	"read_server.h"
#include	"file.h"
#include	"xaccept.h"
#include	"swrite.h"

static void     read_file(t_server *serv, int s)
{
  t_file	*file;
  char		buf[512];
  char		ret[1024];
  int		fd;
  int		r;

  if ((r = read(s, buf, 511)) > 0)
    {
      buf[r] = 0;
      if ((file = get_file_by_fd(serv->files, s)) != NULL)
	{
	  sprintf(ret, ".downloads/%s", file->name);
	  if ((fd = open(ret, \
			 O_CREAT | O_APPEND | O_RDWR, 0666)) != -1)
	    {
	      swrite(fd, buf);
	      close(fd);
	    }
	}
    }
  else
    {
      close(s);
      serv->fd_type[s] = FD_FREE;
    }
}

void		file_read(t_server *serv, int s)
{
  t_file	*file;

  struct sockaddr_in	csin;
  socklen_t		len;
  int			cs;

  len = sizeof(csin);
  cs = xaccept(s, (struct sockaddr *)&csin, &len);

  if ((file = get_file_by_fd(serv->files, s)) != NULL)
    file->fd = cs;

  serv->fd_type[cs] = FD_WFILE_READ;
  serv->fct_read[cs] = read_file;
  serv->fct_write[cs] = NULL;

  close(s);
  serv->fd_type[s] = FD_FREE;
}

static void	shutting_down(t_server *serv, t_file *file, char *ret, int s)
{
  remove(ret);
  serv->files = pop_file(serv->files, file->from, file->to);

  close(s);
  serv->fd_type[s] = FD_FREE;
}

static void	write_file(t_server *serv, int s)
{
  t_file	*file;
  char		buf[512];
  char		ret[1024];
  int		fd;
  int		r;

  if ((file = get_file_by_fd(serv->files, s)) != NULL)
    {
      sprintf(ret, ".downloads/%s", file->name);
      if ((fd = open(ret, O_RDONLY)) != -1)
	{
	  if ((r = read(fd, buf, 511)) > 0)
	    {
	      buf[r] = 0;
	      swrite(s, buf);
	      close(fd);
	    }
	  else
	    shutting_down(serv, file, ret, s);
	}
    }
}

void		file_write(t_server *serv, int s)
{
  t_file	*file;

  struct sockaddr_in	csin;
  socklen_t		len;
  int			cs;

  len = sizeof(csin);
  cs = xaccept(s, (struct sockaddr *)&csin, &len);

  if ((file = get_file_by_fd(serv->files, s)) != NULL)
    file->fd = cs;

  serv->fd_type[cs] = FD_WFILE_WRITE;
  serv->fct_read[cs] = write_file;
  serv->fct_write[cs] = NULL;

  close(s);
  serv->fd_type[s] = FD_FREE;
}
