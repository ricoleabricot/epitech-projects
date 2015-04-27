/*
** main.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 15:04:14 2014 Pierrick Gicquelais
** Last update Wed Mar  5 17:21:53 2014 Pierrick Gicquelais
*/

#include	<signal.h>
#include	"shell2.h"

int		main(int argc, char **argv, char **envp)
{
  t_list	*list;
  char		**env;

  (void)argc;
  (void)argv;
  list = init_list();
  my_env(list, envp);
  env = env_cpy(list);
  //  signal(SIGINT, SIG_IGN);
  my_putstr("Kafei-sh2$> ");
  parent_process(list, env);
  return (0);
}
