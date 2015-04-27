/*
** check_error.c for corewar in /home/boisso_c/Documents/corewar
**
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
**
** Started on  Tue Apr  8 15:32:41 2014 Christian Boisson
** Last update Sat Apr 12 12:04:41 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"op.h"
#include	"creat_cor.h"
#include	"asm.h"

void		check_error(t_list *list, t_label *label)
{
  check_label_are_rights(list, label);
  label_exist(list, label, 0);
  check_params(list);
  check_reg(list);
  check_indirect(list, -1);
  check_direct(list, -1);
}

void		label_exist(t_list *list, t_label *label, int j)
{
  t_list	*tmp;
  int		i;
  int		dif;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->args[0], "label") != 0)
	{
	  j = 1;
	  while (tmp->args[++j])
	    {
	      i = 0;
	      if (tmp->args[j][0] == '%' && tmp->args[j][1] == ':')
		{
		  dif = 1;
		  while (dif != 0 && label[i].name != NULL)
		    dif = my_strlcmp(tmp->args[j], label[i++].name, 2);
		  if (dif != 0)
		    my_error(2, "Undefined label ", tmp->line, tmp->args[j]);
		}
	    }
	}
      tmp = tmp->next;
    }
}

void		check_params(t_list *list)
{
  t_list	*tmp;
  int		i;
  int		j;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->args[0], "label") != 0)
	{
	  i = 0;
	  while ((op_tab[i].mnemonique &&				\
		  my_strcmp(tmp->args[0], op_tab[i++].mnemonique)) != 0);
	  if (tmp->argnbr != op_tab[i - 1].nbr_args)
	    my_error(0, "Invalid parameter number", tmp->line, "YOLO");
	  j = -1;
	  while (tmp->args[1][++j])
	    choice_error(tmp, j, i - 1);
	}
      tmp = tmp->next;
    }
}

void		choice_error(t_list *tmp, int j, int i)
{
  if (tmp->args[1][j] == 'R' && (op_tab[i].type[j] & 1) == 0)
    my_error(0, "Invalid parameter", tmp->line, "RRR");
  else if (tmp->args[1][j] == 'D' && (op_tab[i].type[j] & 2) == 0)
    my_error(0, "Invalid parameter", tmp->line, "DDD");
  else if (tmp->args[1][j] == 'L' && (op_tab[i].type[j] & 2) == 0)
    my_error(0, "Invalid parameter", tmp->line, "LLL");
  else if (tmp->args[1][j] == 'I' && (op_tab[i].type[j] & 4) == 0)
    my_error(0, "Invalid parameter", tmp->line, "III");
}

void		check_reg(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->args[0], "label") != 0)
	check_reg2(tmp->args, tmp->line);
      tmp = tmp->next;
    }
}
