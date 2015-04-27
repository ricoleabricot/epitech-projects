/*
** put_var.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Mar 28 12:55:16 2014 Christian Boisson
** Last update Fri Apr 11 16:26:45 2014 Christian Boisson
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"op.h"
#include	"asm.h"
#include	"creat_cor.h"

void		put_reg(int fd, char *arg)
{
  int		nb;

  arg++;
  nb = my_getnbr(arg);
  arg--;
  if (write(fd, &nb, 1) == -1)
    exit(-1);
}

void		put_label(int fd, char *arg, t_label *label, int pos)
{
  int		nb;
  int		i;
  int		dif;
  int		rpos;

  dif = 1;
  i = 0;
  while (dif != 0 && label[i].name != NULL)
    {
      dif = my_strlcmp(arg, label[i].name, 2);
      i++;
    }
  rpos = label[i - 1].pos - pos;
  nb = rev_int(rpos);
  if (write(fd, &nb, 4) == -1)
    exit(-1);
}

void		put_dir(int fd, char *arg)
{
  int		nb;

  arg++;
  nb = rev_int(my_getnbr(arg));
  arg--;
  if (write(fd, &nb, 4) == -1)
    exit(-1);
}

void		put_ind(int fd, char *arg)
{
  int		nb;
  char		oct_a;
  char		oct_b;

  nb = my_getnbr(arg);
  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0xFF;
  if (write(fd, &oct_b, 1) == -1)
    exit(-1);
  if (write(fd, &oct_a, 1) == -1)
    exit(-1);
}
