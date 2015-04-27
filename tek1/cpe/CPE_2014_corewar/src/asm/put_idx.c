/*
** put_idx.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/src/asm
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Apr 11 16:22:31 2014 Christian Boisson
** Last update Sat Apr 12 12:02:56 2014 Nicolas Ribeiro Teixeira
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"creat_cor.h"
#include	"lib.h"

void		put_idx_label(int fd, char *arg, t_label *label, int pos)
{
  int		nb;
  int		i;
  int		dif;
  int		rpos;
  char		oct_a;
  char		oct_b;

  dif = 1;
  i = 0;
  while (dif != 0 && label[i].name != NULL)
    {
      dif = my_strlcmp(arg, label[i].name, 2);
      i++;
    }
  rpos = label[i - 1].pos - pos;
  nb = rpos;
  nb = nb % IDX_MOD;
  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0XFF;
  if (write(fd, &oct_b, 1) == -1)
    exit (-1);
  if (write(fd, &oct_a, 1) == -1)
    exit (-1);
}

void		put_idx_dir(int fd, char *arg)
{
  int		nb;
  char		oct_a;
  char		oct_b;

  arg++;
  nb = my_getnbr(arg);
  nb = nb % IDX_MOD;
  arg--;
  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0xFF;
  if (write(fd, &oct_b, 1) == -1)
    exit (-1);
  if (write(fd, &oct_a, 1) == -1)
    exit (-1);

}
