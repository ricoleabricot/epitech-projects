/*
** init.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 13:17:24 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:57:09 2015 Pierrick Gicquelais
*/

#include	"init_client.h"
#include	"xgetprotobyname.h"
#include	"xsocket.h"
#include	"xconnect.h"
#include	"serror.h"

void		init_passive(t_client *cli, char *ip, char *port)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;

  pe = xgetprotobyname("TCP");
  cli->sf = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(port));
  sin.sin_addr.s_addr = inet_addr(ip);

  xconnect(cli->sf, (const struct sockaddr *)&sin, sizeof(sin));
}

void		first_init(t_client *cli)
{
  cli->ip = NULL;
  cli->port = NULL;

  cli->nick = NULL;
  cli->ch = NULL;

  cli->is_connected = false;
  cli->fd = 0;

  cli->sf = 0;
  cli->filename = NULL;
}

void		init(t_client *cli)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;

  if (cli->ip != NULL && cli->port != NULL)
    {
      pe = xgetprotobyname("TCP");
      cli->fd = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);

      sin.sin_family = AF_INET;
      sin.sin_port = htons(atoi(cli->port));
      sin.sin_addr.s_addr = inet_addr(cli->ip);

      xconnect(cli->fd, (const struct sockaddr *)&sin, sizeof(sin));
      cli->is_connected = true;

      cli->nick = strdup("Anonymous");
    }
  else
    cli->is_connected = false;
}
