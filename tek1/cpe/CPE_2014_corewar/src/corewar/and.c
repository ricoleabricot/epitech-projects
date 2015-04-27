/*
** and.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:03:16 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:22:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_and(t_vm *vm, t_champ *ch)
{
  int		p1;
  int		p2;

  if ((ch->instru->coding >> 6 & 0x3) == 1)
    p1 = ch->reg[getmem(ch->instru->param[0], 1) - 1];
  else if ((ch->instru->coding >> 6 & 0x3) == 2)
    p1 = getmem(ch->instru->param[0], 4);
  else if ((ch->instru->coding >> 6 & 0x3) == 3)
    p1 = get_int(getmem(ch->instru->param[0], 2), vm->arena->arena, 4);
  if ((ch->instru->coding >> 4 & 0x3) == 1)
    p2 = ch->reg[getmem(ch->instru->param[1], 1) - 1];
  else if ((ch->instru->coding >> 4 & 0x3) == 2)
    p2 = getmem(ch->instru->param[1], 4);
  else if ((ch->instru->coding >> 4 & 0x3) == 3)
    p2 = get_int(getmem(ch->instru->param[1], 2), vm->arena->arena, 4);
  ch->reg[getmem(ch->instru->param[2], 1) - 1] = p1 & p2;
  return (ch->reg[getmem(ch->instru->param[2], 1) - 1]);
}
