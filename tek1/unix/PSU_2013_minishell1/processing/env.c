/*
** env.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Dec 20 09:40:39 2013 Pierrick Gicquelais
** Last update Fri Dec 20 19:11:46 2013 Pierrick Gicquelais
*/

#include	"../shell.h"

char		**my_env(char **envp)
{
  char		**env;
  int		i;
  int		j;

  i  = 0;
  while (envp[i++]);
  if ((env = malloc((i - 1) * sizeof(char *) + 1)) == NULL)
    my_error("Error with a memory allocation");
  i = -1;
  while (envp[++i])
    {
      j = -1;
      if ((env[i] = malloc(my_strlen(envp[i]) * sizeof(char) + 1)) == NULL)
        my_error("Error with a memory allocation");
      while (envp[i][++j])
        env[i][j] = envp[i][j];
      env[i][j] = '\0';
    }
  return (env);
}
