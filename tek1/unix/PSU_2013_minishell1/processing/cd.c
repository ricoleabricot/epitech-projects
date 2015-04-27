/*
** cd.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Dec 20 19:06:52 2013 Pierrick Gicquelais
** Last update Sat Dec 21 16:31:52 2013 Pierrick Gicquelais
*/

#include	"../shell.h"

void		my_opt_cd(char **tab, char **env, int i, int j)
{
  char		*home;
  int		k;

  k = -1;
  if (tab[1] == '\0')
    {
      while (env[++i][0] != 'H' || env[i][1] != 'O' ||  \
             env[i][2] != 'M' || env[i][3] != 'E');
      home = malloc(my_strlen(env[i]) * sizeof(char));
      while (env[i][++j])
        home[++k] = env[i][j];
    }
  else if (tab[1][0] == '-')
    {
      j = 6;
      while (env[++i][3] != 'P' || env[i][4] != 'W' || env[i][5] != 'D');
      home = malloc(my_strlen(env[i]) * sizeof(char));
      while (env[i][++j])
        home[++k] = env[i][j];
      my_putstr(home);
      my_putchar('\n');
    }
  chdir(home);
}

void		my_cd(char *s, char **tab, char **env)
{
  int	i;
  int	j;

  i = -1;
  j = 4;
  if (s[0] == 'c' && s[1] == 'd')
    {
      if ((access(tab[1], F_OK & R_OK) == -1) && tab[1] && tab[1][0] != '-')
        {
          my_putstr("bash: cd: ");
          my_putstr(tab[1]);
          my_putstr(": No such file or directory\n");
        }
      if (tab[1] == '\0' || tab[1][0] == '-')
        my_opt_cd(tab, env, i, j);
      else
        chdir(tab[1]);
    }
}
