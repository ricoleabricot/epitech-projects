/*
** builtin.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb 25 15:20:56 2014 Pierrick Gicquelais
** Last update Wed Mar  5 18:36:32 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		my_exit(t_list *list, char *s, char **tab, char **env)
{
  if (tab[2])
    {
      my_printf("bash: exit: too much arguments\n");
      return (1);
    }
  if (tab[1])
    {
      my_free(list, s, tab, env);
      exit(my_getnbr(tab[1]));
    }
  else
    {
      my_free(list, s, tab, env);
      exit(EXIT_SUCCESS);
    }
}

int		my_next_builtin(t_list *list, char *s, char **tab, char **env)
{
  if (tab[0] && my_strcmp("cd", tab[0]) == 0)
    {
      my_cd(tab, env);
      return (1);
    }
  else if (tab[0] && my_strcmp("exit", tab[0]) == 0)
    {
      my_exit(list, s, tab, env);
      return (1);
    }
  return (0);
}

int		my_builtin(t_list *list, char *s, char **tab, char **env)
{
  int		i;

  if (s[0] == '\0')
    return (1);
  else if (my_strcmp("env", s) == 0)
    {
      i = 0;
      while (env[i])
	{
	  my_putstr(env[i++]);
	  my_putchar('\n');
	}
      return (1);
    }
  else if (tab[0] && my_strcmp("setenv", tab[0]) == 0)
    {
      my_setenv(list, tab);
      return (1);
    }
  else if (tab[0] && my_strcmp("unsetenv", tab[0]) == 0)
    {
      my_unsetenv(list, tab);
      return (1);
    }
  return (my_next_builtin(list, s, tab, env));
}
