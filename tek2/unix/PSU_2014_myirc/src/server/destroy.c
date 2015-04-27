/*
** destroy.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:26:56 2015 Pierrick Gicquelais
** Last update Fri Apr 24 12:25:11 2015 Pierrick Gicquelais
*/

#include	"destroy_server.h"
#include	"user.h"
#include	"channel.h"

static void	clean_folder(void)
{
  DIR		*dirp;
  struct dirent	*file;
  char		path[512];

  if ((dirp = opendir(".downloads")) != NULL)
    {
      while ((file = readdir(dirp)))
	{
	  sprintf(path, "%s/%s", ".downloads", file->d_name);
	  remove(path);
	}
      closedir(dirp);
    }
  else
    {
      perror("Opendir");
      exit(EXIT_FAILURE);
    }
}

static void	close_sockets(t_server *serv)
{
  int		i;

  i = 0;
  while (i < FD_MAX)
    {
      if (serv->fd_type[i] != FD_FREE)
	{
	  printf("Connection closed from fd n°%d\n", i);
	  close(i);
	}
      i++;
    }
}

void		destroy(t_server *serv)
{
  close_sockets(serv);
  clean_folder();

  if (serv->users != NULL)
    free_users(serv->users);
  if (serv->channels != NULL)
    free_channels(serv->channels);
  if (serv != NULL)
    free(serv);
  printf("Bye.\n");
}
