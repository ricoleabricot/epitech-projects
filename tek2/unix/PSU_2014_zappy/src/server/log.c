/*
** log.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jul  1 11:52:38 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:35:06 2015 Pierrick Gicquelais
*/

#include	"server/log.h"

void		logs(char *str, char *type)
{
  char		buf[100];
  char		*filename;
  time_t	now;
  int		fd;

  mkdir(".logs", 0775);
  now = time(0);

  strftime (buf, 100, "%Y-%m-%d", localtime (&now));
  asprintf(&filename, ".logs/%s-%s.log", type, buf);
  fd = xopen(filename, O_CREAT | O_APPEND | O_RDWR, 0666);

  swrite(fd, str);
  free(filename);

  close(fd);
}
