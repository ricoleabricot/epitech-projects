/*
** exec.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 15:31:35 2014 Pierrick Gicquelais
** Last update Wed Mar  5 17:35:49 2014 Pierrick Gicquelais
*/

#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		my_execution(char *cmd, char **tab, char **env)
{
  char		**path;
  char		*cat;
  int		j;

  j = 0;
  if (access(cmd, X_OK) == 0)
    execve(cmd, tab, env);
  while (my_strncmp(env[++j], "PATH=", 5) != 0);
  path = my_env_to_wordtab(env[j]);
  j = -1;
  while (path[++j])
    {
      cat = my_strcat(path[j], cmd);
      if (access(cat, X_OK) == 0)
	execve(cat, tab, env);
      free(cat);
      free(path[j]);
    }
  free(path);
  return (0);
}

void		my_fork(char *cmd, char **tab, char **env)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    child_process(cmd, tab, env);
  else
    waitpid(pid, 0, WSTOPPED);
}
