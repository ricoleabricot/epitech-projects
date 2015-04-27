/*
** malloc.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar  6 13:58:27 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:00:57 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

char		**my_file_malloc(char * file)
{
  char		**tab;
  char		*s;
  int		fd;
  int		i;

  i = 1;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("Error 24: Error with syscall open", 24);
  while ((s = get_next_line(fd)) != NULL)
    {
      i++;
      free(s);
    }
  if ((tab = malloc(i * sizeof(char **))) == NULL)
    my_error("Error 124: Error with a memory allocation", 124);
  close(fd);
  return (tab);
}
