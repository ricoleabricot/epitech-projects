/*
** client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 13:18:56 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:51:32 2015 Pierrick Gicquelais
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<stdbool.h>
# include	<signal.h>
# include	<ctype.h>
# include	<fcntl.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<sys/socket.h>

# include	<netinet/in.h>
# include	<arpa/inet.h>

typedef struct	s_client t_client;
struct		s_client
{
  fd_set	fd_read;

  char		*ip;
  char		*port;

  char		*nick;
  char		*ch;

  bool		is_connected;
  int		fd;

  int		sf;
  char		*filename;
};

#endif		/* !CLIENT_H_ */
