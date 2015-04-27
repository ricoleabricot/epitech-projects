/*
** process.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 15:05:57 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:15:55 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

void		child_process(char *cmd, char **tab, char **env)
{
  int		i;

  i = 0;
  if (my_execution(cmd, tab, env) == 0)
    {
      my_printf("bash: ");
      while (tab[i])
	{
	  my_putstr(tab[i++]);
	  my_putchar(' ');
	}
      my_printf(": command not found\n");
    }
  exit(EXIT_SUCCESS);
}

void		my_cmd(t_list *list, char *s, char **env, int i)
{
  char		*epur_s;
  char		**tab;

  epur_s = epur_str(s);
  tab = my_str_to_wordtab(epur_s, &i);
  if ((my_builtin(list, s, tab, env)) == 0 &&		\
      check_redir(epur_s, tab, env, i) == 0)
      my_fork(tab[0], tab, env);
  if (check_env(tab, env) == 1)
    env = env_cpy(list);
  check_recurs(list, s, env, i - 1);
  my_mini_free(epur_s, tab);
}

void		parent_process(t_list *list, char **env)
{
  char		*s;
  int		i;

  while ((s = get_next_line(0)) != NULL)
    {
      i = 0;
      my_cmd(list, s, env, i);
      free(s);
    }
  my_eof_free(list, s, env);
}
