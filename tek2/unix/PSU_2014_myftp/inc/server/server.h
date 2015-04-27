/*
** server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/inc/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:08:04 2015 Pierrick Gicquelais
** Last update Fri Mar 27 16:53:07 2015 Pierrick Gicquelais
*/

#ifndef		SERVER_H_
# define	SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<netdb.h>

# define	SAVE_FILE	(".save")
# define        MAN_FILE	(".man")

typedef struct	s_data	t_data;
struct		s_data
{
  struct protoent	*protocol;
  struct sockaddr_in	sin;
  struct sockaddr_in	csin;
  socklen_t		len;
  int			fd;
  int			cfd;
};

typedef struct	s_server t_server;
struct		s_server
{
  t_data		*data;

  char			*ip;
  char			*port;

  struct protoent	*protocol;
  struct sockaddr_in	sin;
  struct sockaddr_in	csin;
  socklen_t		len;
  int			fd;
  int			cfd;

  char			*root;
  char			*save_file;
  char			*username;
  bool			login;
};

#endif		/* !SERVER_H_ */
