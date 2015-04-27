/*
** zjmp.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:19:03 2014 Pierrick Gicquelais
** Last update Sat Apr 12 11:58:13 2014 Christian Boisson
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_zjmp(t_vm *vm, t_champ *ch)
{
  if (ch->carry == 1)
    ch->pc += (getmem(ch->instru->param[0], 2)) % IDX_MOD;
  (void)vm;
  return (1);
}
