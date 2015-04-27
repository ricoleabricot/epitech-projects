/*
** read.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 14:37:54 2015 Pierrick Gicquelais
** Last update Wed Apr 15 14:18:36 2015 Pierrick Gicquelais
*/

#include	"read_server.h"
#include	"user.h"
#include	"commands.h"
#include	"broadcast.h"
#include	"xaccept.h"
#include	"swrite.h"

static void	delete_client(t_server *serv, t_user *user, int s, int r)
{
  char		ret[512];

  if ((user->buf_size + r) > 512)
    swrite(user->fd, "You shouldn't have speak this much :)\r\n");
  else
    swrite(user->fd, "Good bye fellow !\r\n");

  if (user->ch != NULL)
    {
      sprintf(ret, ":%s QUIT %s\r\n", user->nick, user->ch);
      broadcast(serv, user, ret);
    }

  serv->users = pop_user(serv->users, s);

  close(s);
  serv->fd_type[s] = FD_FREE;
  printf("Connection close from fd n°%d\n", s);
}

static void     listen_client(t_server *serv, t_user *user, char *buf, int r)
{
  user->buf_size += r;
  strcat(user->buf, buf);
  if (user->buf[strlen(user->buf) - 1] == '\n')
    {
      user->buf[strlen(user->buf)] = '\0';
      commands(serv, user, user->buf);
      memset(user->buf, 0, 512);
      user->buf_size = 0;
    }
}

void		client_read(t_server *serv, int s)
{
  t_user	*user;
  char		buf[512];
  int		r;

  user = get_user_by_fd(serv->users, s);
  memset(buf, 0, 512);
  if ((r = read(s, buf, 512)) > 0 && (user->buf_size + r) < 512)
    listen_client(serv, user, buf, r);
  else
    delete_client(serv, user, s, r);
}

void		server_read(t_server *serv, int s)
{
  struct sockaddr_in	csin;
  socklen_t		len;
  char			nick[16];
  int			cs;

  len = sizeof(csin);
  cs = xaccept(s, (struct sockaddr *)&csin, &len);

  serv->fd_type[cs] = FD_CLIENT;
  serv->fct_read[cs] = client_read;
  serv->fct_write[cs] = NULL;

  sprintf(nick, "Anonymous%d", cs);
  serv->users = append_user(serv->users, cs, nick);
  printf("New client on file descriptor n°%d\n", cs);
  swrite(cs, "001 RPL_WELCOME :Welcome in KafeIRC, don't flood\r\n");
  swrite(cs, "002 RPL_YOURHOST :Your host is localhost, running v1.2\r\n");
  swrite(cs, "003 RPL_CREATED :This server was created april, 5th 2015\r\n");
  swrite(cs, "004 RPL_MYINFO :localhost 1.2 u|o 0|1\r\n");
}
