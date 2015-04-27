/*
** aff.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:11:55 2014 Pierrick Gicquelais
** Last update Sat Apr 12 12:00:19 2014 Christian Boisson
*/

#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		my_aff(t_vm *vm, t_champ *ch)
{
  char		param;

  param = ch->reg[getmem(ch->instru->param[0], 1) - 1] % 256;
  my_putchar(param);
  (void)vm;
  return (1);
}
