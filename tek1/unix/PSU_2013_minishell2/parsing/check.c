/*
** check.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2/parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar  5 13:58:23 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:08:14 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

int		check_redir(char *s, char **tab, char **env, int i)
{
  char		*file;
  char		c1;
  char		c2;

  c1 = s[i - 1];
  c2 = s[i];
  if ((c1 == '>' && c2 != '>') || (c1 == '<' && c2 != '<') || c1 == '|')
    file = my_strdup(s, i + 1);
  else
    file = my_strdup(s, i + 2);
  if (c1 == '>' && c2 != '>')
    return (redir_right(tab[0], tab, env, file));
  else if (c1 == '>' && c2 == '>')
    return (redir_do_right(tab[0], tab, env, file));
  else if (c1 == '<' && c2 != '<')
    return (redir_left(tab[0], env, file));
  else if (c1 == '<' && c2 == '<')
    return (redir_do_left(tab[0], tab, env, file));
  else if (c1 == '|')
    return (my_pipe(tab[0], tab, env, file));
  free(file);
  return (0);
}

int		check_env(char **tab, char **env)
{
  if (tab[0] && my_strcmp("setenv", tab[0]) == 0)
    {
      my_free_env(env);
      return (1);
    }
  else if (tab[0] && my_strcmp("unsetenv", tab[0]) == 0)
    {
      my_free_env(env);
      return (1);
    }
  return (0);
}

int		check_cd(char **env)
{
  int		i;
  int		flag1;
  int		flag2;

  i = 0;
  flag1 = 0;
  flag2 = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "OLDPWD=", 7) == 0)
	flag1 = 1;
      if (my_strncmp(env[i], "HOME=", 5) == 0)
	flag2 = 1;
      i++;
    }
  if (flag1 == 1 && flag2 == 1)
    return (0);
  return (1);
}

int		check_recurs(t_list *list, char *s, char **env , int i)
{
  if (s[i] && s[i] == ';')
    my_cmd(list, s, env, i + 2);
  else
    my_putstr("Kafei-sh2$> ");
  return (0);
}
