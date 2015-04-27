/*
** client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:07:24 2015 Pierrick Gicquelais
** Last update Fri Mar 27 17:34:53 2015 Pierrick Gicquelais
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<netdb.h>

typedef struct	s_data	t_data;
struct		s_data
{
  struct protoent       *protocol;
  struct sockaddr_in    sin;
  struct sockaddr_in    csin;
  socklen_t             len;
  int                   fd;
  int                   cfd;
};

typedef struct	s_client t_client;
struct		s_client
{
  t_data		*data;

  struct protoent	*protocol;
  struct sockaddr_in	sin;
  int			fd;
  char			*username;
  bool			login;
};

#endif		/* !CLIENT_H_ */
