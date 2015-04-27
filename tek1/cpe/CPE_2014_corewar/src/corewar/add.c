/*
** add.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:01:16 2014 Pierrick Gicquelais
** Last update Sat Apr 12 13:00:36 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_add(t_vm *vm, t_champ *ch)
{
  ch->reg[getmem(ch->instru->param[2], 1) - 1] =   \
    ch->reg[getmem(ch->instru->param[1], 1) - 1] + \
    ch->reg[getmem(ch->instru->param[0], 1) - 1];
  (void)vm;
  return (ch->reg[getmem(ch->instru->param[2], 1) - 1]);
}
