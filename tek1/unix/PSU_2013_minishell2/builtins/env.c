/*
** env.c for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Dec 20 09:40:39 2013 Pierrick Gicquelais
** Last update Wed Mar  5 18:51:47 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

void		my_env(t_list *list, char **envp)
{
  int		i;

  i = 0;
  while (envp[i])
    {
      append_list(list, envp[i]);
      i++;
    }
}

char		**env_cpy(t_list *list)
{
  t_node	*node;
  char		**environ;
  int		i;

  i = 0;
  node = list->head;
  if ((environ = malloc((list->count + 1) * sizeof(char *))) == NULL)
    my_error("Error 31: Error with a memory allocation", 31);
  while (node)
    {
      environ[i] = my_strlcpy(node->env, 0);
      node = node->next;
      i++;
    }
  environ[i] = '\0';
  return (environ);
}

char		*my_strenv(char *dest, char *src)
{
  char		*str;
  int		i;
  int		j;
  int		k;

  i = 0;
  j  = 0;
  k = 0;
  if ((str = malloc                                                     \
       ((my_strlen(src) + my_strlen(dest) + 2) * sizeof(char))) == NULL)
    my_error("Error 124: Error with a memory allocation", 124);
  while (dest[i])
    str[k++] = dest[i++];
  if (dest[i - 1] != '=')
    str[k++] = '=';
  while (src[j])
    str[k++] = src[j++];
  str[k] = '\0';
  return (str);
}

void		my_setenv(t_list *list, char **tab)
{
  char		*cat;

  if (tab[1] && tab[2])
    {
      delete_list(list, tab[1], 0);
      cat = my_strenv(tab[1], tab[2]);
      append_list(list, cat);
      free(cat);
    }
  else
    my_printf("bash: setenv: must have only two arguments\n");
}

void		my_unsetenv(t_list *list, char **tab)
{
  if (tab[1])
    delete_list(list, tab[1], 1);
  else
    my_printf("bash: unsetenv: you must enter an argument\n");
}
