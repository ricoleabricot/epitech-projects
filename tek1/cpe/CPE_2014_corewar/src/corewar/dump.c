/*
** dump.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 13:39:19 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:20:05 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		put_nbrhexa(int nb, char *base)
{
  if (nb / 16 > 0)
    put_nbrhexa(nb / 16, base);
  my_putchar(base[nb % 16]);
}

void		dump_arena(t_vm *vm)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (i % 32 == 0)
	my_printf("\nLine %d: \t", i / 32 + 1);
      if (vm->arena->arena[i] < 16)
	my_putchar('0');
      put_nbrhexa(vm->arena->arena[i], "0123456789ABCDEF");
      i++;
    }
  my_putchar('\n');
}
