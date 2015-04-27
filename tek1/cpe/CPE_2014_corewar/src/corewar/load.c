/*
** load.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:16:03 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:21:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_ld(t_vm *vm, t_champ *ch)
{
  if ((ch->instru->coding >> 6 & 0x3) == 2)
    ch->reg[getmem(ch->instru->param[1], 1) - 1] =	\
      getmem(ch->instru->param[0], 4);
  else if ((ch->instru->coding >> 6 & 0x3) == 3)
    ch->reg[getmem(ch->instru->param[1], 1) - 1] =	\
      get_int(ch->pc + \
	      (getmem(ch->instru->param[0], 2)) %	\
	      IDX_MOD, vm->arena->arena, 4);
  return (ch->reg[getmem(ch->instru->param[1], 1) - 1]);
}

int		my_ldi(t_vm *vm, t_champ *ch)
{
  int		pos;

  if ((ch->instru->coding >> 6 & 0x3) == 1)
    pos = ch->reg[getmem(ch->instru->param[0], 1) - 1] % IDX_MOD;
  else if ((ch->instru->coding >> 6 & 0x3) == 2)
    pos = getmem(ch->instru->param[0], 2) % IDX_MOD;
  else if ((ch->instru->coding >> 6 & 0x3) == 3)
    pos = get_int(ch->pc + getmem(ch->instru->param[0], 2) % \
		  IDX_MOD, vm->arena->arena, 4);
  if ((ch->instru->coding >> 4 & 0x3) == 1)
    pos += ch->reg[getmem(ch->instru->param[1], 1) - 1];
  else if ((ch->instru->coding >> 4 & 0x3) == 2)
    pos += getmem(ch->instru->param[1], 2);
  ch->reg[getmem(ch->instru->param[2], 1) - 1] = get_int(pos % IDX_MOD, \
							 vm->arena->arena, 4);
  return (ch->reg[getmem(ch->instru->param[2], 1) - 1]);
}

int		my_lld(t_vm *vm, t_champ *ch)
{
  if ((ch->instru->coding >> 6 & 0x3) == 2)
    ch->reg[getmem(ch->instru->param[1], 1) - 1] =	\
      getmem(ch->instru->param[0], 4);
  else if ((ch->instru->coding >> 6 & 0x3) == 3)
    ch->reg[getmem(ch->instru->param[1], 1) - 1] =	\
      get_int(ch->pc + \
	      getmem(ch->instru->param[0], 2), vm->arena->arena, 4);
  return (ch->reg[getmem(ch->instru->param[1], 1) - 1]);
}

int		my_lldi(t_vm *vm, t_champ *ch)
{
  int		pos;

  if ((ch->instru->coding >> 6 & 0x3) == 1)
    pos = ch->reg[getmem(ch->instru->param[0], 1) - 1];
  else if ((ch->instru->coding >> 6 & 0x3) == 2)
    pos = getmem(ch->instru->param[0], 2);
  else if ((ch->instru->coding >> 6 & 0x3) == 3)
    pos = get_int(ch->pc + getmem(ch->instru->param[0], 2), \
		  vm->arena->arena, 4);
  if ((ch->instru->coding >> 4 & 0x3) == 1)
    pos += ch->reg[getmem(ch->instru->param[1], 1) - 1];
  else if ((ch->instru->coding >> 4 & 0x3) == 2)
    pos += getmem(ch->instru->param[1], 2);
  ch->reg[getmem(ch->instru->param[2], 1) - 1] = get_int(pos, \
							 vm->arena->arena, 4);
  return (ch->reg[getmem(ch->instru->param[2], 1) - 1]);
}
