/*
** live.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:14:08 2014 Pierrick Gicquelais
** Last update Sat Apr 12 16:34:01 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		my_show_alive_champions(t_vm *vm)
{
  int		i;

  i = 0;
  my_printf("Champions alive :\n");
  while (i < vm->champ_nbr)
    {
      if (vm->ch[i] != NULL)
	my_printf("Prog Number : %d ------> \"%s\"\n", \
		  vm->info[i].prog_nbr, vm->info[i].name);
      i++;
    }
}

int		my_live(t_vm *vm, t_champ *ch)
{
  int		nb;
  int		i;

  i = 0;
  nb = getmem(ch->instru->param[0], 4);
  while (i < vm->champ_nbr)
    {
      if (vm->info[i].prog_nbr == nb)
	{
	  vm->ch[i]->live = 1;
	  vm->nbr_live++;
	  my_printf("Le joueur n°%d (%s) est en vie.\n", \
		    vm->info[i].prog_nbr, vm->info[i].name);
	  return (1);
	}
      i++;
    }
  return (1);
}
