/*
** protocol.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Mar 28 20:21:36 2015 Pierrick Gicquelais
** Last update Sun Apr 12 17:48:54 2015 Pierrick Gicquelais
*/

#include	"protocol.h"
#include	"init_client.h"
#include	"split_string.h"
#include	"swrite.h"

static char	*get_ip(char *ret)
{
  char		*s1;
  char		*s2;
  char		*s3;
  char		*s4;
  char		ip[32];

  s1 = split_string(ret, ',', 0);
  s2 = split_string(ret, ',', 1);
  s3 = split_string(ret, ',', 2);
  s4 = split_string(ret, ',', 3);

  sprintf(ip, "%s.%s.%s.%s", s1, s2, s3, s4);

  free(s1);
  free(s2);
  free(s3);
  free(s4);

  return (strdup(ip));
}

static char	*get_port(char *ret)
{
  char		*p1;
  char		*p2;
  char		port[32];

  p1 = split_string(ret, ',', 4);
  p2 = split_string(ret, ',', 5);

  sprintf(port, "%d", atoi(p1) * 256 + atoi(p2));

  free(p1);
  free(p2);

  return (strdup(port));
}

void		pasv(t_client *cli, char *buf)
{
  char		*scmd;
  char		*ip;
  char		*port;

  scmd = split_string(buf, '(', 1);
  ip = get_ip(scmd);
  port = get_port(scmd);

  init_passive(cli, ip, port);

  free(scmd);
  free(ip);
  free(port);
}
