/*
** redirection.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2/processing
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Mar  4 10:57:47 2014 Pierrick Gicquelais
** Last update Thu Mar  6 13:59:55 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		redir_do_left(char *cmd, char **tab, char **env, char *file)
{
  char		*s;
  pid_t		pid;

  my_putstr(">> ");
  while ((s = get_next_line(0)) != NULL && my_strcmp(s, file) != 0)
    my_putstr(">> ");
  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    child_process(cmd, tab, env);
  else
    waitpid(pid, 0, WSTOPPED);
  return (1);
}

int		redir_left(char *cmd, char **env, char *file)
{
  char		*s;
  char		**tab;
  pid_t		pid;
  int		fd;
  int		i;

  i = 0;
  my_printf("Copying command from file: %s\n", file);
  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    {
      if ((fd = open(file, O_RDONLY)) == -1)
	my_error("Error 24: Error with syscall open", 24);
      tab = my_file_malloc(file);
      while ((s = get_next_line(fd)) != NULL)
	{
	  tab[i++] = my_strlcpy(s, 0);
	  free(s);
	}
      child_process(cmd, tab, env);
    }
  else
    waitpid(pid, 0, WSTOPPED);
  return (1);
}

int		redir_do_right(char *cmd, char **tab, char **env, char *file)
{
  pid_t		pid;
  int		fd;

  my_printf("Writting in file: %s\n", file);
  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    {
      if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, \
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	my_error("Error 24: Error with syscall open", 24);
      dup2(fd, 1);
      child_process(cmd, tab, env);
    }
  else
    waitpid(pid, 0, WSTOPPED);
  return (1);
}

int		redir_right(char *cmd, char **tab, char **env, char *file)
{
  pid_t		pid;
  int		fd;

  my_printf("Writting in file: %s\n", file);
  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    {
      if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, \
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	my_error("Error 24: Error with syscall open", 24);
      dup2(fd, 1);
      child_process(cmd, tab, env);
    }
  else
    waitpid(pid, 0, WSTOPPED);
  return (1);
}
