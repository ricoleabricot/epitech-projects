/*
** store.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:17:21 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:22:21 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_st(t_vm *vm, t_champ *ch)
{
  if ((ch->instru->coding >> 4 & 0x3) == 1)
    ch->reg[getmem(ch->instru->param[1], 1) - 1] =	\
      ch->reg[getmem(ch->instru->param[0], 1) - 1];
  else if ((ch->instru->coding >> 4 & 0x3) == 3)
    write_arena(ch->pc + (getmem(ch->instru->param[1], 2) % IDX_MOD), \
		vm->arena->arena, ch->reg[getmem(ch->instru->param[0], 1)]);
  return (1);
}

int		my_sti(t_vm *vm, t_champ *ch)
{
  int		pos;

  if ((ch->instru->coding >> 4 & 0x3) == 1)
    pos = ch->reg[getmem(ch->instru->param[1], 1) - 1];
  else if ((ch->instru->coding >> 4 & 0x3) == 2)
    pos = getmem(ch->instru->param[1], 2);
  else if ((ch->instru->coding >> 4 & 0x3) == 3)
    pos = get_int(ch->pc + getmem(ch->instru->param[1], 2) % IDX_MOD, \
		  vm->arena->arena, 4);
  if ((ch->instru->coding >> 2 & 0x3) == 1)
    pos += ch->reg[getmem(ch->instru->param[2], 1) - 1];
  else if ((ch->instru->coding >> 2 & 0x3) == 2)
    pos += getmem(ch->instru->param[2], 2);
  write_arena(ch->pc + pos % IDX_MOD, vm->arena->arena, \
	      ch->reg[getmem(ch->instru->param[0], 1) - 1]);
  return (1);
}
