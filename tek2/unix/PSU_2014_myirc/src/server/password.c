/*
** password.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:30:50 2015 Pierrick Gicquelais
** Last update Fri Apr 10 18:49:15 2015 Pierrick Gicquelais
*/

#include	"password.h"
#include	"split_string.h"
#include	"getnextline.h"
#include	"swrite.h"

bool		password_exists(char *nick, int fd)
{
  char		*s;
  int		xfd;

  if ((xfd = open(".save", O_RDWR)) != -1)
    {
      if (strncasecmp(nick, "anonymous", strlen("anonymous")) == 0)
        return (true);

      while ((s = getnextline(xfd)) != NULL)
	{
	  if (strncmp(nick, s, strlen(nick)) == 0)
            {
              free(s);
              return (true);
	    }
	  free(s);
	}
      close(xfd);
    }
  else
    swrite(fd, "424 :Save file missing\r\n");
  return (false);
}

bool		password_correct(char *nick, char *pass, int fd)
{
  char		*tmpn;
  char		*tmpp;
  char		*s;
  int		xfd;

  if ((xfd = open(".save", O_RDWR)) != -1)
    {
      while ((s = getnextline(xfd)) != NULL)
        {
	  tmpn = split_string(s, ':', 0);
	  tmpp = split_string(s, ':', 1);

	  if (tmpn != NULL && tmpp != NULL)
	    if (strcmp(nick, tmpn) == 0 && strcmp(pass, tmpp) == 0)
	      return (true);

	  free(tmpn);
	  free(tmpp);
          free(s);
        }
      close(xfd);
    }
  else
    swrite(fd, "424 :Save file missing\r\n");
  return (false);
}
