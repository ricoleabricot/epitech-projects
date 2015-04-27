/*
** my_label_found2.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/asm
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Apr  9 16:29:11 2014 Nicolas Ribeiro Teixeira
** Last update Sun Apr 13 20:13:18 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"asm.h"
#include	"op.h"

char		*my_dup_label(char *str, int dp)
{
  char		*label;
  int		i;

  if ((label = malloc(sizeof(char) * (dp + 2))) == NULL)
    exit(0);
  i = 0;
  while (i != dp)
    {
      label[i] = str[i];
      i++;
    }
  label[i] = '\0';
  return (label);
}

t_list		*my_create_new_eleme_args(t_list *new_elem, char *str,
					  int tonbouy, int dp)
{
  char		*string;
  char		**args;

  if (tonbouy == 1)
    {
      if ((new_elem->args = malloc(sizeof(char *) * 3)) == NULL)
	exit(0);
      new_elem->args[0] = "label";
      new_elem->args[1] = my_dup_label(str, dp);
      new_elem->args[2] = NULL;
    }
  else
    {
      string = my_cut_str(dp, str);
      args = special_instruction(string, new_elem->line);
      new_elem->args = args;
      new_elem->argnbr = (args != NULL) ? my_getnbr(args[1]) : 0;
    }
  return (new_elem);
}

t_list		**my_special_append(char *str, t_list **begin,
				    int tonbouy, int line)
{
  int		dp;
  t_list	*new_elem;
  t_list	*tmp;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    exit(0);
  new_elem->next = NULL;
  dp = my_special_doublepoint_pos(str);
  new_elem->line = line;
  new_elem = my_create_new_eleme_args(new_elem, str, tonbouy, dp);
  if (*begin == NULL)
    {
      *begin = new_elem;
      return (begin);
    }
  tmp = *begin;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_elem;
  return (begin);
}

t_list		**my_special_case_found(char *str, t_list **begin, int line)
{
  begin = my_special_append(str, begin, 1, line);
  begin = my_special_append(str, begin, 2, line);
  return (begin);
}

int		spec_case(char *str, t_list **begin, int line, int *label_nbr)
{
  int		dp;

  dp = my_special_doublepoint_pos(str);
  if (dp == -1)
    return (1);
  if (dp > 0 && str[dp - 1] != DIRECT_CHAR)
    {
      while (str[++dp])
	{
	  if (str[dp] != ' ' && str[dp] != '\t' && str[dp] != '\0')
	    {
	      begin = my_special_case_found(str, begin, line);
	      (*label_nbr)++;
	      return (0);
	    }
	}
      return (1);
    }
  else
    return (1);
}

