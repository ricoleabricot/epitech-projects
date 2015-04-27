/*
** authentication.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Mar 17 15:11:36 2015 Pierrick Gicquelais
** Last update Fri Mar 27 13:14:20 2015 Pierrick Gicquelais
*/

#include	"authentication.h"
#include	"encryption.h"
#include	"session.h"
#include	"is_alphanumeric.h"
#include	"trim.h"
#include	"user_exists.h"
#include	"xopen.h"
#include	"getnextline.h"
#include	"split_string.h"
#include	"swrite.h"

void	        find_account(t_server *serv, char *user)
{
  if (user_exists(serv, user) == false)
    swrite(serv->cfd, "332 Username not existing\r\n");
  else
    {
      serv->username = strdup(user);
      swrite(serv->cfd, "331 Username okay, need password\r\n");
    }
}

void		authentication(t_server *serv, char *pass)
{
  char		*s;
  char		*tmp;
  int		fd;
  bool		end;

  end = false;
  fd = xopen(serv->save_file, O_RDONLY, 0);
  while ((s = getnextline(fd)) != NULL && !end)
    {
      tmp = split_string(s, ':', 1);
      if (tmp != NULL)
	{
	  if (strcmp(encryption(pass), tmp) == 0)
	    end = true;
	  free(tmp);
	}
      free(s);
    }
  if (end == false)
    swrite(serv->cfd, "332 Wrong password\r\n");
  else
    connect_session(serv);
}

bool		check_value(t_server *serv, char *user, char *pass)
{
  if (!is_alphanumeric(user))
    {
      swrite(serv->cfd, "503 Username must be alphanumeric\r\n");
      return (false);
    }
  else if (strlen(user) < 4 || strlen(user) > 16)
    {
      swrite(serv->cfd, \
	     "503 Username must be between 4 and 16 characters\r\n");
      return (false);
    }
  else if (!is_alphanumeric(pass))
    {
      swrite(serv->cfd, "503 Password must be alphanumeric\r\n");
      return (false);
    }
  else if (strlen(pass) < 4 || strlen(pass) > 16)
    {
      swrite(serv->cfd, \
	     "503 Password must be between 4 and 16 characters\r\n");
      return (false);
    }
  return (true);
}
