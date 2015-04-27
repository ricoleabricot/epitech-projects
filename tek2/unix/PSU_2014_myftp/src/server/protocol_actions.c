/*
** protocol_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 27 11:37:22 2015 Pierrick Gicquelais
** Last update Fri Mar 27 17:30:37 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"init_server.h"
#include	"split_string.h"
#include	"xaccept.h"
#include	"swrite.h"

void		type(t_server *serv, char *cmd)
{
  (void)cmd;
  swrite(serv->cfd, "220 Type set to ASCII mode\r\n");
}

void		pasv(t_server *serv, char *cmd)
{
  char	        value[4096];
  int		port;

  (void)cmd;
  port = init_passive(serv->data);
  sprintf(value, "220 PASV Command Successful (127,0,0,1,%d,%d)\r\n", \
	  port / 256, port % 256);
  swrite(serv->cfd, value);

  serv->data->cfd = xaccept(serv->data->fd, (struct sockaddr *)\
			    &serv->data->csin, &serv->data->len);
}

static void	initialize_port(t_server *serv, char *ip, char *scmd)
{
  char		*p1;
  char		*p2;
  char		port[32];

  p1 = split_string(scmd, ',', 4);
  p2 = split_string(scmd, ',', 5);

  sprintf(port, "%d", atoi(p1) * 256 + atoi(p2));
  if (init_active(serv->data, ip, port) == 0)
    swrite(serv->cfd, "200 PORT Command Successful\r\n");
  else
    swrite(serv->cfd, "500 Invalid PORT\r\n");
  free(p1);
  free(p2);
}

void		port(t_server *serv, char *cmd)
{
  char		*scmd;
  char		*s1;
  char		*s2;
  char		*s3;
  char		*s4;
  char		ip[32];

  scmd = split_string(cmd, ' ', 1);
  s1 = split_string(scmd, ',', 0);
  s2 = split_string(scmd, ',', 1);
  s3 = split_string(scmd, ',', 2);
  s4 = split_string(scmd, ',', 3);

  sprintf(ip, "%s.%s.%s.%s", s1, s2, s3, s4);
  initialize_port(serv, ip, scmd);

  free(scmd);
  free(s1);
  free(s2);
  free(s3);
  free(s4);
}
