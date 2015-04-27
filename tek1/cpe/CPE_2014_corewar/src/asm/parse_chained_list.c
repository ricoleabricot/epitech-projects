/*
** parse_chained_list.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
**
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
**
** Started on Thu Mar 27 09:57:57 2014 Nicolas Ribeiro Teixeira
** Last update Wed Apr  9 12:12:10 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"lib.h"
#include	"op.h"

char		*my_create_codebyte_from_doubletab(t_list *tmp, int i)
{
  int		k;

  k = 0;
  while (++i != tmp->argnbr)
    {
      if (tmp->args[i + 2][0] == DIRECT_CHAR)
	{
	  if (tmp->args[i + 2][1] == ' ' || tmp->args[i + 2][1] == '\t')
	    my_error(0, NULL, tmp->line, NULL);
	  else if (tmp->args[i + 2][1] == LABEL_CHAR &&
		   (tmp->args[i + 2][2] == ' ' || tmp->args[i + 2][2] == '\t'))
	    my_error(0, NULL, tmp->line, NULL);
	  else if (tmp->args[i + 2][1] == LABEL_CHAR)
	    tmp->args[1][k] = 'L';
	  else
	    tmp->args[1][k] = 'D';
	}
      else if (tmp->args[i + 2][0] == 'r')
	tmp->args[1][k] = 'R';
      else
	tmp->args[1][k] = 'I';
      k++;
    }
  tmp->args[1][k] = '\0';
  return (tmp->args[1]);
}

t_list		*parse_chained_list(t_list *begin)
{
  t_list	*tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      if (tmp->args != NULL)
	{
	  if (my_strcmp(tmp->args[0] , "label") != 0 && tmp->args[1] != NULL)
	    {
	      if ((tmp->args[1] = malloc(sizeof(char) *
					(tmp->argnbr + 1))) == NULL)
		exit(0);
	      tmp->args[1] = my_create_codebyte_from_doubletab(tmp, -1);
	    }
	}
      tmp = tmp->next;
    }
  return (begin);
}
