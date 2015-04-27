/*
** init.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:37:14 2015 Pierrick Gicquelais
** Last update Fri Mar 27 17:00:39 2015 Pierrick Gicquelais
*/

#include	"init_server.h"
#include	"xsocket.h"
#include	"xgetprotobyname.h"
#include	"xbind.h"
#include	"xlisten.h"
#include	"xaccept.h"
#include	"xconnect.h"
#include	"xgetcwd.h"
#include	"xmalloc.h"
#include	"xchdir.h"
#include	"swrite.h"
#include	"merror.h"

int		init_passive(t_data *data)
{
  data->protocol = xgetprotobyname("TCP");
  data->fd = xsocket(AF_INET, SOCK_STREAM, data->protocol->p_proto);

  data->sin.sin_family = AF_INET;
  data->sin.sin_port = 0;
  data->sin.sin_addr.s_addr = INADDR_ANY;

  xbind(data->fd, (const struct sockaddr *)&data->sin, sizeof(data->sin));
  xlisten(data->fd, 1);
  data->len = sizeof(data->csin);
  getsockname(data->fd, (struct sockaddr *)&data->sin, &data->len);

  return (ntohs(data->sin.sin_port));
}

int		init_active(t_data *data, char *ip, char *port)
{
  data->protocol = xgetprotobyname("TCP");
  data->cfd = xsocket(AF_INET, SOCK_STREAM, data->protocol->p_proto);

  data->csin.sin_family = AF_INET;
  data->csin.sin_port = htons(atoi(port));
  data->csin.sin_addr.s_addr = inet_addr(ip);

  return (connect(data->cfd, \
		  (const struct sockaddr *)&data->csin, sizeof(data->csin)));
}

void		init(t_server *serv)
{
  serv->data = xmalloc(sizeof(t_data));

  serv->root = xmalloc(PATH_MAX);
  if (realpath(".session/anonymous/", serv->root) == NULL)
    merror("Rpath Error");
  serv->save_file = xmalloc(PATH_MAX);
  if (realpath(".save", serv->save_file) == NULL)
    merror("Rpath Error");

  xchdir(serv->root);
  serv->username = NULL;
  serv->login = false;
  serv->protocol = xgetprotobyname("TCP");
  serv->fd = xsocket(AF_INET, SOCK_STREAM, serv->protocol->p_proto);

  serv->sin.sin_family = AF_INET;
  serv->sin.sin_port = htons(atoi(serv->port));
  serv->sin.sin_addr.s_addr = INADDR_ANY;

  xbind(serv->fd, (const struct sockaddr *)&serv->sin, sizeof(serv->sin));
  xlisten(serv->fd, 1);
  serv->len = sizeof(serv->csin);
}
