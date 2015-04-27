/*
** put_all.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Thu Mar 27 12:32:54 2014 Christian Boisson
** Last update Sat Apr 12 12:02:49 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"op.h"
#include	"asm.h"
#include	"creat_cor.h"
#include	"lib.h"

void		put_instruct(int fd, t_list *list, t_label *label)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->args[0], "label") != 0)
	{
	  put_opcode(fd, tmp->args[0]);
	  put_coding(fd, tmp->args[0], tmp->args[1]);
	  put_arg(fd, label, tmp->args, tmp->octet);
	}
      tmp = tmp->next;
    }
}

void		put_opcode(int fd, char *instruc)
{
  int		i;

  i = 0;
  while (my_strcmp(instruc, op_tab[i].mnemonique)
	 && op_tab[i].mnemonique != '\0')
    i++;
  if (write(fd, &op_tab[i].code, sizeof(char)) == -1)
    exit(-1);
}

void		put_coding(int fd, char *name, char *param)
{
  int		i;
  unsigned char	coding;

  i = 0;
  coding = 0;
  if (my_strcmp(name, "zjmp") != 0 && my_strcmp(name, "live") != 0 &&	\
      my_strcmp(name, "fork") != 0 && my_strcmp(name, "lfork") != 0)
    {
      while (param[i])
	{
	  if (param[i] == 'R')
	    coding += 1;
	  else if (param[i] == 'D' || param[i] == 'L')
	    coding += 2;
	  else if (param[i] == 'I')
	    coding += 3;
	  coding = coding * 4;
	  i++;
	}
      while (++i < 4)
	coding = coding * 4;
      if (write(fd, &coding, 1) == -1)
	exit(-1);
    }
}

void		put_arg(int fd, t_label *label, char **args, int pos)
{
  int		i;

  i = 2;
  if (my_strcmp(args[0], "zjmp") == 0 || my_strcmp(args[0], "ldi") == 0|| \
      my_strcmp(args[0], "sti") == 0 || my_strcmp(args[0], "fork") == 0|| \
      my_strcmp(args[0], "lldi") == 0 || my_strcmp(args[0], "lfork") == 0)
    put_idx_arg(fd, label, args, pos);
  else
    while (args[i])
    {
      if (args[i][0] == 'r')
	put_reg(fd, args[i]);
      else if (args[i][0] == DIRECT_CHAR)
      	{
      	  if (args[i][1] == LABEL_CHAR)
      	    put_label(fd, args[i], label, pos);
      	  else
      	    put_dir(fd, args[i]);
      	}
      else
      	put_ind(fd, args[i]);
      i++;
    }
}

void		put_idx_arg(int fd, t_label *label, char **args, int pos)
{
  int		i;

  i = 2;
  while (args[i])
    {
      if (args[i][0] == 'r')
	put_reg(fd, args[i]);
      else if (args[i][0] == DIRECT_CHAR)
	{
	  if (args[i][1] == LABEL_CHAR)
	    put_idx_label(fd, args[i], label, pos);
	  else
	    put_idx_dir(fd, args[i]);
	}
      else
	put_ind(fd, args[i]);
      i++;
    }
}
