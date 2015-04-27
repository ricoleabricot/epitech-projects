/*
** no_error.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Apr 15 15:35:49 2015 Pierrick Gicquelais
** Last update Wed Apr 15 21:41:00 2015 Pierrick Gicquelais
*/

#include	"no_error.h"
#include	"is_reply.h"
#include	"split_string.h"

static bool	check_read(char *filename)
{
  struct stat	st;
  int		fd;

  stat(filename, &st);
  if ((fd = open(filename, O_RDONLY)) == -1 || !S_ISREG(st.st_mode))
    {
      printf("424 ERR_FILERROR :No such file\r\n");
      return (false);
    }

  if (filename != NULL)
    free(filename);

  close(fd);
  return (true);
}

bool		no_error(char *cmd)
{
  char		*filename;

  filename = split_string(cmd, ' ', 2);
  if (strncmp(SEND, cmd, strlen(SEND)) == 0)
    return (check_read(filename));

  return (true);
}
