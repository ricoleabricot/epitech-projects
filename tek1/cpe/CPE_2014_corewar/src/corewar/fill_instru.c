/*
** fill_intru.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/Elfen
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Thu Apr 10 00:04:43 2014 Christian Boisson
** Last update Sat Apr 12 13:00:50 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		fill_instru(int op, char coding, t_champ *champ, int flag)
{
  if (flag == 0)
    {
      champ->instru->exec_cycle = -1;
      champ->instru->opcode = 0;
      champ->instru->coding = 0;
    }
  else
    {
      champ->instru->opcode = op;
      champ->instru->coding = coding;
      champ->instru->exec_cycle = op_tab[op - 1].nbr_cycles;
    }
}

void		fill_param(t_champ *ch, \
			   unsigned char arena[MEM_SIZE], int num, int size)
{
  int		i;
  int		tmp;
  int		j;

  j = 2;
  if (arena[ch->pc] == 1 || arena[ch->pc] == 9 ||
      arena[ch->pc] == 12 || arena[ch->pc] == 15)
    j--;
  i = 0;
  tmp = size;
  while (tmp > 0)
    {
      ch->instru->param[num][i] = arena[ch->pc + j + ch->instru->coding + i];
      tmp--;
      i++;
    }
  while (i < 5)
    {
      ch->instru->param[num][i] = '\0';
      i++;
    }
  ch->instru->coding += size;
  ch->instru->size += size;
}
