/*
** main.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Dec 11 14:40:02 2013 Pierrick Gicquelais
** Last update Sat Dec 21 17:01:55 2013 Pierrick Gicquelais
*/

#include "shell.h"

int	main(int argc, char **argv, char **envp)
{
  char	**env;

  env = my_env(envp);
  signal(SIGINT, SIG_IGN);
  my_putstr("$> ");
  parent_process(env);
  return (0);
}
