/*
** term.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jan 14 14:56:48 2014 Pierrick Gicquelais
** Last update Wed Jan 15 16:28:57 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../select.h"

char		*find_term(char **envp)
{
  char		*str;
  int		i;
  int		j;
  int		k;

  i = -1;
  j = 4;
  k = 0;
  if (envp[++i] == '\0')
    my_error("Environment disabled. End of programm");
  while ((envp[++i][0] != 'T' || envp[i][1] != 'E' ||                   \
          envp[i][2] != 'R' || envp[i][3] != 'M') && envp[i] != '\0');
  if ((str = malloc(my_strlen(envp[i]) * sizeof(char))) == NULL)
    my_error("Error with a memory allocation");
  while (envp[i][++j])
    {
      str[k] = envp[i][j];
      k++;
    }
  return (str);
}
