/*
** fork.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 09:20:05 2014 Pierrick Gicquelais
** Last update Sun Apr 13 20:01:01 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

t_champ		*my_copy_int_tab(int reg[REG_NUMBER], t_champ *new)
{
  int		i;

  i = 0;
  while (i != REG_NUMBER)
    {
      new->reg[i] = reg[i];
      i++;
    }
  return (new);
}

t_champ		*my_append_to_champ(t_champ *ch, int pluspc)
{
  t_champ	*new_process;
  t_champ	*tmp;

  if ((new_process = malloc(sizeof(t_champ))) == NULL)
    my_print_error("Error with a memory allocation\n");
  if ((new_process->instru = malloc(sizeof(t_champ))) == NULL)
    my_print_error("Error with a memory allocation\n");
  new_process->instru->exec_cycle = -1;
  new_process->pc = ch->pc + pluspc;
  new_process = my_copy_int_tab(ch->reg, new_process);
  new_process->live = ch->live;
  new_process->carry = ch->carry;
  new_process->next = NULL;
  if (ch == NULL)
    return (new_process);
  tmp = ch;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_process;
  return (ch);
}

int		my_fork(t_vm *vm, t_champ *ch)
{
  int		pluspc;

  if (vm != NULL)
    {
      pluspc = getmem(ch->instru->param[0], 2) % MEM_SIZE;
      pluspc = pluspc % IDX_MOD;
      ch = my_append_to_champ(ch, pluspc);
    }
  return (1);
}

int		my_lfork(t_vm *vm, t_champ *ch)
{
  int		pluspc;

  if (vm != NULL)
    {
      pluspc = getmem(ch->instru->param[0], 2) % MEM_SIZE;
      ch = my_append_to_champ(ch, pluspc);
    }
  return (1);
}
