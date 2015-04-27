/*
** server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:19:20 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:20:01 2015 Pierrick Gicquelais
*/

#ifndef		SERVER_H_
# define	SERVER_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<string.h>
# include	<fcntl.h>
# include	<dirent.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<sys/socket.h>
# include	<sys/time.h>

# include	<arpa/inet.h>
# include	<netinet/in.h>

# define	FD_FREE		0
# define	FD_CLIENT	1
# define	FD_SERVER	2

# define	FD_SFILE_READ	3
# define	FD_WFILE_READ	4

# define	FD_SFILE_WRITE	5
# define	FD_WFILE_WRITE	6

# define	FD_MAX	        1024

typedef		void(*fct)();

typedef struct	s_file	  t_file;
struct		s_file
{
  t_file	*prev;
  t_file	*next;

  char		*from;
  char		*to;
  char		*name;

  int		fd;
};

typedef struct	s_op	  t_op;
struct		s_op
{
  t_op		*prev;
  t_op		*next;

  char		*nick;
};

typedef struct	s_channel t_channel;
struct		s_channel
{
  t_channel	*prev;
  t_channel	*next;

  char		*name;
  char		*topic;
  t_op		*ops;

  char		*toinvite;
  bool		private;
};

typedef struct	s_user	 t_user;
struct		s_user
{
  t_user	*prev;
  t_user	*next;

  int		fd;
  char		*ch;
  char		*nick;

  char		buf[512];
  int		buf_size;

  char		*username;
  char		*host;
  char		*servername;
  char		*realname;

  int		sf;
};

typedef struct	s_server t_server;
struct		s_server
{
  char			fd_type[FD_MAX];
  fct			fct_read[FD_MAX];
  fct			fct_write[FD_MAX];

  int			s;
  int			port;
  struct timeval	tv;

  t_user		*users;
  t_channel		*channels;
  t_file		*files;
};

#endif		/* !SERVER_H_ */
