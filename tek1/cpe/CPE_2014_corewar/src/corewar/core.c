/*
** core.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 20:11:45 2014 Pierrick Gicquelais
** Last update Sun Apr 13 19:57:42 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"struct.h"
#include	"funct.h"
#include	"op_func.h"

void		fill_function_tab(int (*function_tab[17])(t_vm *, t_champ *))
{
  function_tab[0] = &my_void;
  function_tab[1] = &my_live;
  function_tab[2] = &my_ld;
  function_tab[3] = &my_st;
  function_tab[4] = &my_add;
  function_tab[5] = &my_sub;
  function_tab[6] = &my_and;
  function_tab[7] = &my_or;
  function_tab[8] = &my_xor;
  function_tab[9] = &my_zjmp;
  function_tab[10] = &my_ldi;
  function_tab[11] = &my_sti;
  function_tab[12] = &my_fork;
  function_tab[13] = &my_lld;
  function_tab[14] = &my_lldi;
  function_tab[15] = &my_lfork;
  function_tab[16] = &my_aff;
}

int		corewar(t_vm *vm)
{
  int		(*function_tab[17])(t_vm *, t_champ *);
  int		i;

  i = 0;
  my_printf("Welcome in the Corewar. Let the fight begin !\n");
  if (vm->dump_nbr != -1)
    my_printf("Dump Number: %d\n", vm->dump_nbr);
  my_printf("List of champs: \n");
  while (i < vm->champ_nbr)
    {
      init_reg(vm->ch[i], &vm->info[i]);
      my_printf("Champion n°%d: %s (%s) load at adress: %d\n", \
		vm->info[i].prog_nbr, vm->info[i].name, \
                vm->info[i].comment, vm->info[i].load_adress);
      i++;
    }
  fill_function_tab(function_tab);
  vm->cycle = 0;
  vm->cycle_to_die = 0;
  vm->nbr_live = 0;
  game(vm, function_tab, 0, 0);
  return (0);
}
