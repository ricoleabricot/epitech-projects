/*
** user_exists.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 17 16:28:05 2015 Pierrick Gicquelais
** Last update Fri Mar 27 13:13:56 2015 Pierrick Gicquelais
*/

#include	"user_exists.h"
#include	"xopen.h"
#include	"getnextline.h"
#include	"split_string.h"

bool		user_exists(t_server *serv, char *username)
{
  char		*s;
  int		fd;

  if (strcasecmp(username, "anonymous") == 0)
    return (true);
  fd = xopen(serv->save_file, O_RDONLY, 0);
  while ((s = getnextline(fd)) != NULL)
    {
      if (strncmp(username, s, strlen(username)) == 0)
	return (true);
      free(s);
    }
  return (false);
}
