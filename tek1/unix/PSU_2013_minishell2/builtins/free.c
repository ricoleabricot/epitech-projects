/*
** free.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 28 13:27:58 2014 Pierrick Gicquelais
** Last update Tue Mar  4 10:34:22 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell2.h"

void		my_free(t_list *list, char *s, char **tab, char **env)
{
  t_node	*node;
  t_node	*tmp;
  int		i;

  node = list->head;
  while (node)
    {
      free(node->env);
      tmp = node->next;
      free(node);
      node = tmp;
    }
  free(list);
  i = 0;
  while (env[i])
    free(env[i++]);
  free(env);
  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
  free(s);
}

void		my_eof_free(t_list *list, char *s, char **env)
{
  t_node	*node;
  t_node	*tmp;
  int		i;

  i = 0;
  node = list->head;
  while (node)
    {
      free(node->env);
      tmp = node->next;
      free(node);
      node = tmp;
    }
  free(list);
  while (env[i])
    free(env[i++]);
  free(env);
  free(s);
}

void		my_mini_free(char *s, char **tab)
{
  int           i;

  i = 0;
  if (s[0])
    {
      while (tab[i])
	free(tab[i++]);
      free(tab);
      free(s);
    }
}

void		my_free_env(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    free(env[i++]);
  free(env);
}
