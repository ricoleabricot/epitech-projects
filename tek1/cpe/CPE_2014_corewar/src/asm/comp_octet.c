/*
** comp_octet.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Wed Mar 26 11:36:35 2014 Christian Boisson
** Last update Fri Apr 11 16:48:04 2014 Christian Boisson
*/

#include	"op.h"
#include	"creat_cor.h"
#include	"asm.h"
#include	"lib.h"

int		comp_octet(t_list *list, t_label *label, int total_size)
{
  t_list	*tmp;
  int		size;
  int		i;

  i = 0;
  size = 0;
  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->args[0], "label") == 0)
	{
	  label[i].name = my_strdup(tmp->args[1]);
	  label[i].pos = total_size + 1;
	  tmp->octet = total_size + 1;
	  i++;
	}
      else
	{
	  size = instruct_size(tmp->args[0], tmp->args[1]);
	  tmp->octet = total_size + 1;
	  total_size += size;
	}
      tmp = tmp->next;
    }
  return (total_size);
}

int		instruct_size(char *name, char *param)
{
  int		i;
  int		size;

  i = 0;
  if (my_strcmp(name, "zjmp") == 0 || my_strcmp(name, "live") == 0 ||	\
      my_strcmp(name, "fork") == 0 || my_strcmp(name, "lfork") == 0)
    size = 1;
  else
    size = 2;
  if (my_strcmp(name, "zjmp") == 0 || my_strcmp(name, "ldi") == 0 ||	\
      my_strcmp(name, "sti") == 0 || my_strcmp(name, "fork") == 0 ||	\
      my_strcmp(name, "lldi") == 0 || my_strcmp(name, "lfork") == 0)
    size += inst_idx_size(param);
  else
    while (param[i])
      {
	if (param[i] == 'R')
	  size += 1;
	else if (param[i] == 'D' || param[i] == 'L')
	  size += 4;
	else if (param[i] == 'I')
	  size += 2;
	i++;
      }
  return (size);
}

int		inst_idx_size(char *param)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (param[i])
    {
      if (param[i] == 'R')
	size += 1;
      else if (param[i] == 'D' || param[i] == 'L' || \
	       param[i] == 'I')
	size += 2;
      i++;
    }
  return (size);
}
