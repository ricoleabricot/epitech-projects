/*
** session.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar 18 14:00:21 2015 Pierrick Gicquelais
** Last update Wed Mar 25 14:57:04 2015 Pierrick Gicquelais
*/

#include	"session.h"
#include	"xchdir.h"
#include	"xgetcwd.h"
#include	"xmalloc.h"
#include	"swrite.h"

void		connect_session(t_server *serv)
{
  char		newroot[PATH_MAX];

  if (serv->login == false)
    {
      serv->login = true;
      sprintf(newroot, "../%s", serv->username);
      xchdir(newroot);
      serv->root = xgetcwd(".", serv->root);
      swrite(serv->cfd, "230 User logged in, proceed\r\n");
    }
  else
    swrite(serv->cfd, "533 You're already connected, please log out\r\n");
}

void		disconnect_session(t_server *serv)
{
  if (serv->login == true)
    {
      serv->username = NULL;
      serv->login = false;
      swrite(serv->cfd, "220 Disconnected\r\n");
    }
  else
    swrite(serv->cfd, "530 You're not connected\r\n");
}

void		create_session(t_server *serv, int fd, char *user, char *pass)
{
  char		*path;

  path = xmalloc(PATH_MAX);
  dprintf(fd, "%s:%s\n", user, pass);
  sprintf(path, "%s/../%s", serv->root, user);
  mkdir(path, 0775);
  swrite(serv->cfd, "220 User created, you can now log in\r\n");
}
