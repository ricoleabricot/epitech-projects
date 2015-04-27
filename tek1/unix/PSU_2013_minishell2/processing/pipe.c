/*
** pipe.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2/processing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar  5 15:34:02 2014 Pierrick Gicquelais
** Last update Thu Mar  6 13:46:47 2014 Pierrick Gicquelais
*/

#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

void		redir_pipe(char *cmd, char **tab, char **env, char *file)
{
  char		**tab2;
  int		pipefd[2];
  int		fd;
  int		pid;
  int		i;

  i = 0;
  tab2 = my_str_to_wordtab(file, &i);
  if ((fd = pipe(pipefd)) == -1)
    my_error("Error 28: Error with syscall pipe", 28);
  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  if (pid == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      child_process(cmd, tab, env);
    }
  else
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      child_process(tab2[0], tab2, env);
    }
}

int		my_pipe(char *cmd, char **tab, char **env, char *file)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    my_error("Error 25: Error with syscall fork", 25);
  else if (pid == 0)
    redir_pipe(cmd, tab, env, file);
  else
    waitpid(pid, 0, WSTOPPED);
  return (1);
}
