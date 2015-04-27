/*
** session_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar 19 16:31:33 2015 Pierrick Gicquelais
** Last update Fri Mar 27 13:00:44 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"session.h"
#include	"authentication.h"
#include	"encryption.h"
#include	"split_string.h"
#include	"user_exists.h"
#include	"xopen.h"
#include	"swrite.h"

void		user(t_server *serv, char *cmd)
{
  char		*username;

  username = split_string(cmd, ' ', 1);

  if (username == NULL)
    swrite(serv->cfd, "501 You must enter an username after user command\r\n");
  else
    {
      if (serv->login == true)
	swrite(serv->cfd, "553 You're already logged in, please log out\r\n");
      else if (strcasecmp(username, "anonymous") == 0)
	{
	  serv->username = strdup("anonymous");
	  connect_session(serv);
	}
      else
        find_account(serv, username);
      free(username);
    }
}

void		pass(t_server *serv, char *cmd)
{
  char		*password;

  password = split_string(cmd, ' ', 1);
  if (password == NULL)
    swrite(serv->cfd, "501 You must enter a password after user command\r\n");
  else
    {
      if (serv->login == true)
	swrite(serv->cfd, "553 You're already logged in, please log out\r\n");
      else if (serv->username == NULL)
	swrite(serv->cfd, "332 Need account for login\r\n");
      else
	authentication(serv, password);
    }
}

void		setuser(t_server *serv, char *cmd)
{
  int		fd;
  char		*username;
  char		*password;
  char		*encrypt_password;

  fd = xopen(serv->save_file, O_RDWR | O_APPEND, 0);
  username = split_string(cmd, ' ', 1);
  password = split_string(cmd, ' ', 2);

  if (username == NULL)
    swrite(serv->cfd, "501 You must enter an username after set command\r\n");
  else if (password == NULL)
    swrite(serv->cfd, "501 You must enter a password for username\r\n");
  else if (check_value(serv, username, password))
    {
      if (!user_exists(serv, username))
	{
          encrypt_password = encryption(password);
	  create_session(serv, fd, username, encrypt_password);
	  free(encrypt_password);
	}
      else
	swrite(serv->cfd, "230 User already exists\r\n");
    }
}

void		disconnect(t_server *serv, char *cmd)
{
  (void)cmd;
  disconnect_session(serv);
}
