/*
** exec.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Dec 19 09:20:57 2013 Pierrick Gicquelais
** Last update Fri Dec 27 14:09:59 2013 Pierrick Gicquelais
*/

#include	"../shell.h"

void		my_execution(char **tab, char **env)
{
  char		**tab_env;
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (env[++i][0] != 'P' || env[i][1] != 'A' || \
	 env[i][2] != 'T' || env[i][3] != 'H');
  if ((tab_env = malloc(my_strlen(env[i]) * sizeof(char *) + 1)) == NULL)
    my_error("Error with a memory allocation");
  tab_env = my_env_to_wordtab(env[i]);
  while (tab_env[j])
    {
      execve(my_strcat(tab_env[j], tab[0]), tab, env);
      free(tab_env[j]);
      j++;
    }
  free(tab_env);
}

void		my_builtin(char *s, char **env)
{
  int		i;

  i = -1;
  if (s[0] == '\0')
    {
      while (env[++i])
	free(env[i]);
      free(env);
      exit(EXIT_SUCCESS);
    }
  if (my_strcmp("env", s) == 0)
    {
      while (env[++i])
	{
	  my_putstr(env[i]);
	  my_putchar('\n');
	}
      exit(EXIT_SUCCESS);
    }
}

void		my_alias(char *s, char **tab, char **env)
{
  if (my_strcmp("ll", s) == 0)
    {
      tab[1] = "-l";
      execve("/bin/ls", tab, env);
    }
  if (my_strcmp("la", s) == 0)
    {
      tab[1] = "-la";
      execve("/bin/ls", tab, env);
    }
  if (my_strcmp("l", s) == 0)
    {
      tab[1] = "-laF";
      execve("/bin/ls", tab, env);
    }
  if (my_strcmp("ne", s) == 0)
    {
      tab[1] = "-nw";
      execve("/usr/bin/emacs", tab, env);
    }
  if (my_strcmp("clean", s) == 0)
    {
      tab[1] = "-f *~ ; -f *#";
      execve("/bin/rm", tab, env);
    }
}
