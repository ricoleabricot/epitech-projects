/*
** check_error2.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Apr  4 15:36:17 2014 Christian Boisson
** Last update Fri Apr 11 16:47:17 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"creat_cor.h"
#include	"lib.h"

void		check_label_are_rights(t_list *list, t_label *label)
{
  int		i;
  int		correct;
  int		j;
  int		k;

  i = 0;
  while (label[i].name != NULL)
    {
      j = -1;
      while (label[i].name != NULL && label[i].name[++j])
	{
	  k = -1;
	  correct = 0;
	  while (LABEL_CHARS[++k])
	    {
	      if (label[i].name[j] == LABEL_CHARS[k])
		correct = 1;
	    }
	  if (correct != 1)
	    my_error(0, NULL, my_get_line_nbr(list, label[i].name), NULL);
	  i++;
	}
    }
}

int		my_get_line_nbr(t_list *list, char *label_name)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->args != NULL && my_strcmp(tmp->args[0], "label") == 0)
	{
	  if (my_strcmp(tmp->args[1], label_name) == 0)
	    return (tmp->line);
	}
      tmp = tmp->next;
    }
  return (-1);
}

void		check_reg2(char **args, int pos)
{
  int		i;
  int		nb;

  i = 2;
  while (args[i])
    {
      if (args[i][0] == 'r')
	{
	  args[i]++;
	  nb = my_getnbr(args[i]);
	  args[i]--;
	  if (1 > nb || nb > REG_NUMBER)
	    my_error(3, "No such register line", pos, "YOLO");
	}
      i++;
    }
}

void		check_indirect(t_list *list, int i)
{
  t_list	*tmp;
  int		check;

  tmp = list;
  while (tmp)
    {
      i = -1;
      if (my_strcmp(tmp->args[0], "label") != 0)
	{
	  if (my_strcmp(tmp->args[0], "lld") && my_strcmp(tmp->args[0], "lldi")
	      && my_strcmp(tmp->args[0], "lfork"))
	    {
	      while (tmp->args[1][++i])
		{
		  if (tmp->args[1][i] == 'I')
		    {
		      check = my_getnbr(tmp->args[i + 2]);
		      if (check / IDX_MOD != 0)
			my_error(4, NULL, tmp->line, NULL);
		    }
		}
	    }
	}
      tmp = tmp->next;
    }
}

void		check_direct(t_list *list, int i)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      i = -1;
      if (my_strcmp(tmp->args[0], "label") != 0)
	{
	  while (tmp->args[1][++i])
	    {
	      if (tmp->args[1][i] == 'D')
		my_errnbr(tmp->args[i + 2], tmp->line);
	    }
	}
      tmp = tmp->next;
    }
}
