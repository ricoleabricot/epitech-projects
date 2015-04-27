/*
** init.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:26:07 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:22:19 2015 Pierrick Gicquelais
*/

#include	"init_server.h"
#include	"read_server.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"xgetprotobyname.h"
#include	"xsocket.h"
#include	"xbind.h"
#include	"xlisten.h"
#include	"xmalloc.h"

int		init_passive(t_user *user)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  socklen_t		len;

  pe = xgetprotobyname("TCP");
  user->sf = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = 0;
  sin.sin_addr.s_addr = INADDR_ANY;

  xbind(user->sf, (const struct sockaddr *)&sin, sizeof(sin));
  xlisten(user->sf, 1);
  len = sizeof(sin);
  getsockname(user->sf, (struct sockaddr *)&sin, &len);

  return (ntohs(sin.sin_port));
}

static void	init_complements(t_server *serv)
{
  serv->users = NULL;
  serv->channels = NULL;
  serv->files = NULL;

  serv->channels = append_channel(serv->channels, "#Home");
  serv->channels->topic = strdup("Welcome in #Home channel");
  serv->channels->ops = append_op(serv->channels->ops, "Kafei");
  serv->channels->ops = append_op(serv->channels->ops, "Gabroz");

  serv->channels = append_channel(serv->channels, "#Playing");
  serv->channels->topic = strdup("You're here for playing");
  serv->channels->ops = append_op(serv->channels->ops, "Kafei");
  serv->channels->ops = append_op(serv->channels->ops, "Gabroz");

  serv->channels = append_channel(serv->channels, "#Working");
  serv->channels->topic = strdup("Shhhht, you're supposed to work, here");
  serv->channels->ops = append_op(serv->channels->ops, "Kafei");
  serv->channels->ops = append_op(serv->channels->ops, "Gabroz");
}

void		init(t_server *serv)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;

  memset(serv->fd_type, FD_FREE, FD_MAX);
  pe = xgetprotobyname("TCP");
  serv->s = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(serv->port);
  sin.sin_addr.s_addr = INADDR_ANY;

  xbind(serv->s, (const struct sockaddr *)&sin, sizeof(sin));
  xlisten(serv->s, 1);

  serv->fd_type[serv->s] = FD_SERVER;
  serv->fct_read[serv->s] = server_read;
  serv->fct_write[serv->s] = NULL;

  serv->tv.tv_sec = 20;
  serv->tv.tv_usec = 0;

  init_complements(serv);
}
