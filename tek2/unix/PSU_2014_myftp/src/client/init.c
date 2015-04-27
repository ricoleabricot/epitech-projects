/*
** init.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:12:25 2015 Pierrick Gicquelais
** Last update Fri Mar 27 18:10:10 2015 Pierrick Gicquelais
*/

#include	"init_client.h"
#include	"xsocket.h"
#include	"xgetprotobyname.h"
#include	"xconnect.h"
#include	"xmalloc.h"
#include	"swrite.h"
#include	"merror.h"
#include	"wreturn.h"

void		init_passive(t_data *data, char *ip, char *port)
{
  data->protocol = xgetprotobyname("TCP");
  data->cfd = xsocket(AF_INET, SOCK_STREAM, data->protocol->p_proto);

  data->csin.sin_family = AF_INET;
  data->csin.sin_port = htons(atoi(port));
  data->csin.sin_addr.s_addr = inet_addr(ip);

  xconnect(data->cfd, (const struct sockaddr *)&data->csin, \
	   sizeof(data->csin));
}

void		init(t_client *cli, char **argv)
{
  char		ret[4096];

  cli->data = xmalloc(sizeof(t_data));

  cli->protocol = xgetprotobyname("TCP");
  cli->fd = xsocket(AF_INET, SOCK_STREAM, cli->protocol->p_proto);
  cli->sin.sin_family = AF_INET;
  cli->sin.sin_port = htons(atoi(argv[2]));
  cli->sin.sin_addr.s_addr = inet_addr(argv[1]);
  cli->username = NULL;
  cli->login = false;

  xconnect(cli->fd, (const struct sockaddr *)&cli->sin, sizeof(cli->sin));
  read(cli->fd, ret, 4096);
  write(1, ret, strlen(ret));
}
