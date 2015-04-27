/*
** cd.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar  3 15:11:26 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:08:04 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<shell2.h>

void		my_opt_cd(char **tab, char **env)
{
  char		*home;
  int		i;

  i = 0;
  if (tab[1] == '\0')
    while (env[i])
      {
	if (my_strncmp("HOME=", env[i], 5) == 0)
	  home = my_strlcpy(env[i], 5);
	i++;
      }
  else if (my_strcmp("-", tab[1]) == 0)
    while (env[i])
      {
        if (my_strncmp("OLDPWD=", env[i], 7) == 0)
          {
	    home = my_strlcpy(env[i], 7);
	    my_printf("%s\n", home);
          }
	i++;
      }
  if (home)
    {
      chdir(home);
      free(home);
    }
}

void		my_cd(char **tab, char **env)
{
  if (tab[1] != '\0' && (my_strcmp("-", tab[1]) != 0))
    {
      if (access(tab[1], F_OK & R_OK) == -1)
        my_printf("bash: cd: %s: No such file or directory\n", tab[1]);
      else
	chdir(tab[1]);
    }
  else
    if (env[0] && check_cd(env) == 0)
      my_opt_cd(tab, env);
}
