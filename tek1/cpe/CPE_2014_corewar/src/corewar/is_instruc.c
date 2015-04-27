/*
** vm.c for corewar in /home/boisso_c/Documents/corewar/vm
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Apr  4 16:52:44 2014 Christian Boisson
** Last update Mon Apr 14 13:21:19 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		found_instruc(t_vm *vm, t_champ *tmp)
{
  int		op;

  tmp->instru->size = 0;
  if ((op = try_opcode(vm->arena->arena[tmp->pc])) != -1)
    {
      tmp->instru->size++;
      if (op != 1 && op != 9 && op != 12 && op != 15)
	{
	  tmp->instru->size++;
	  if (try_coding(vm->arena->arena, op, tmp, 0) == -1)
	    tmp->pc += 1;
	}
      else
	{
	  if (fill_no_coding(vm->arena->arena, op, tmp) == -1)
	    tmp->pc += 1;
	}
    }
  else
    tmp->pc += 1;
  if (tmp->instru->exec_cycle != -1)
    tmp->instru->exec_cycle += vm->cycle;
}

int		try_opcode(int opcode)
{
  if (opcode < 1 || opcode > 16)
    return (-1);
  return (opcode);
}

int		try_coding(unsigned char arena[], int op, t_champ *champ, int deca)
{
  int		oct;
  int		i;

  i = 2;
  oct = arena[champ->pc + 1] & 0x3;
  fill_instru(0, 0, champ, 0);
  if (oct != 0)
    return (-1);
  while (++deca <= 3)
    {
      oct = (arena[champ->pc + 1] >> (deca * 2)) & 0x3;
      if (oct == 1 && (!(op_tab[op - 1].type[i] & 1)))
	return (-1);
      else if (oct == 2 && (!(op_tab[op - 1].type[i] & 2)))
	return (-1);
      else if (oct == 3 && (!(op_tab[op - 1].type[i] & 4)))
	return (-1);
      else if (oct > 3 || oct < 0)
	return (-1);
      i--;
    }
  if (try_param(arena, champ, op, arena[champ->pc + 1]) == -1)
    return (-1);
  fill_instru(op, arena[champ->pc + 1], champ, 1);
  return (0);
}

int		try_param(unsigned char arena[], t_champ *champ, int op, int code)
{
  int		oct;
  int		deca;

  deca = 1;
  if (op == 10 || op == 11)
    try_p_ind(arena, champ, op, code);
  else
    while (deca <= 3)
      {
	oct = (code >> (deca * 2)) & 0x3;
	if (oct == 1)
	  {
	    fill_param(champ, arena, 3 - deca, 1);
	    if (getmem(champ->instru->param[3 - deca], 1) < 1 ||
		getmem(champ->instru->param[3 - deca], 1) > 16)
	      return (-1);
	  }
	else if (oct == 2)
	  fill_param(champ, arena, 3 - deca, 2);
	else if (oct == 3)
	  fill_param(champ, arena, 3 - deca, 4);
	deca++;
      }
  return (0);
}
