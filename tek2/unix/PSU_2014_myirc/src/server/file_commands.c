/*
** file_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:40:18 2015 Pierrick Gicquelais
** Last update Wed Apr 15 11:55:26 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"init_server.h"
#include	"read_server.h"
#include	"file.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"swrite.h"

static void     receiving(t_server *serv, t_user *user, \
			  t_user *tosend, char *filename)
{
  char		ret[512];
  int		port;

  sprintf(ret, "%s_%s_%s", user->nick, tosend->nick, filename);
  if (!file_exists(serv->files, ret))
    {
      port = init_passive(user);
      serv->fd_type[user->sf] = FD_SFILE_READ;
      serv->fct_read[user->sf] = file_read;
      serv->fct_write[user->sf] = NULL;

      serv->files = append_file(serv->files, ret, user->sf);

      sprintf(ret, "SEND_FILE :%s: Send Command (127,0,0,1,%d,%d)\r\n", \
	      filename, port / 256, port % 256);
      swrite(user->fd, ret);

      sprintf(ret, ":%s SEND_FILE :%s\r\n", user->nick, filename);
      swrite(tosend->fd, ret);
    }
  else
    swrite(user->fd, "424 ERR_FILERROR :File already exists\r\n");
}

void	        send_file(t_server *serv, t_user *user, char *cmd)
{
  struct stat	st;
  t_user	*tomsg;
  char		*nick;
  char		*file;

  nick = split_string(cmd, ' ', 1);
  file = split_string(cmd, ' ', 2);
  if (nick != NULL && file != NULL)
    {
      stat(file, &st);
      if (open(file, O_RDONLY) != -1 && S_ISREG(st.st_mode))
	{
	  tomsg = get_user_by_nick(serv->users, nick);
	  if (tomsg != NULL)
	    receiving(serv, user, tomsg, file);
	  else
	    swrite(user->fd, "401 ERR_NOSUCHNICK :No such nick\r\n");
	}
      else
	swrite(user->fd, "424 ERR_FILERROR :File error\r\n");
      free(nick);
      free(file);
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}

static void	sending(t_server *serv, t_user *user, t_file *file)
{
  char		ret[512];
  char		*name;
  int		port;

  name = split_string(file->name, '_', 2);
  if (name != NULL)
    {
      port = init_passive(user);
      serv->fd_type[user->sf] = FD_SFILE_WRITE;
      serv->fct_read[user->sf] = file_write;
      serv->fct_write[user->sf] = NULL;

      sprintf(ret, "ACCEPT_FILE :%s: Receive Command (127,0,0,1,%d,%d)\r\n",
	      name, port / 256, port % 256);
      swrite(user->fd, ret);
    }
  else
    swrite(user->fd, "424 ERR_FILEERROR :File error\r\n");
}

void	        accept_file(t_server *serv, t_user *user, char *cmd)
{
  t_file	*file;
  char		*nick;

  nick = split_string(cmd, ' ', 1);
  if (nick != NULL)
    {
      file = get_file_by_fromto(serv->files, nick, user->nick);
      if (file != NULL)
	sending(serv, user, file);
      else
	swrite(user->fd, "502 ERR_USERSDONTMATCH :No file to download\r\n");
    }
  else
    swrite(user->fd, "461 ERR_NEEDMOREPARAMS :Not enough parameters\r\n");
}
