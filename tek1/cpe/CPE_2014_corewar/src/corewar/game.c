/*
** core.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/Elfen
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Wed Apr  9 10:34:36 2014 Christian Boisson
** Last update Mon Apr 14 09:50:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		who_won(t_vm *vm, int force_draw)
{
  int		i;

  i = 0;
  while (i != vm->champ_nbr && force_draw != 1)
    {
      if (vm->ch[i] != NULL)
	{
	  my_putstr("The champion : '");
	  my_putstr(vm->info[i].name);
	  my_putstr("' won !\nCongratulations !\n");
	  return (vm->info[i].pos);
	}
      i++;
    }
  my_putstr("AND !!! It's a draw ... :(\n");
  my_show_alive_champions(vm);
  if (force_draw == 1)
    exit(0);
  return (0);
}

void		game(t_vm *vm, int (*function_tab[17])(t_vm *, t_champ *), \
		     int i, int alive_champ)
{
  t_champ	*tmp;

  init_pc(vm);
  alive_champ = vm->champ_nbr;
  while (alive_champ > 1)
    {
      i = 0;
      while (i < vm->champ_nbr)
	{
	  tmp = vm->ch[i++];
	  while (tmp != NULL)
	    {
	      tmp->pc = tmp->pc % MEM_SIZE;
	      if (tmp->instru->exec_cycle == -1)
		found_instruc(vm, tmp);
	      else if (tmp->instru->exec_cycle == vm->cycle)
		exec_proc(vm, tmp, function_tab);
	      tmp = tmp->next;
	    }
	}
      alive_champ -= check_live(vm);
      vm->cycle++;
      vm->cycle_to_die++;
    }
  who_won(vm, 0);
}

int		check_live(t_vm *vm)
{
  static int	local_cycle_to_die = CYCLE_TO_DIE;
  int		return_value;

  return_value = 0;
  if (vm->cycle_to_die == local_cycle_to_die)
    {
      return_value = check_champ_lives(vm);
      vm->cycle_to_die = 0;
    }
  if (vm->nbr_live >= NBR_LIVE)
    {
      if (local_cycle_to_die - CYCLE_DELTA <= 0)
	local_cycle_to_die = 0;
      else
	local_cycle_to_die -= CYCLE_DELTA;
      vm->nbr_live = 0;
    }
  if (vm->dump_nbr == vm->cycle)
    {
      dump_arena(vm);
      exit(1);
    }
  if (local_cycle_to_die <= DRAW_THRESHOLD)
    who_won(vm, 1);
  return (return_value);
}

int		check_champ_lives(t_vm *vm)
{
  int		dead;
  t_champ	*tmp;
  int		i;
  int		liveactual;

  i = -1;
  dead = 0;
  liveactual = 0;
  while (++i < vm->champ_nbr)
    {
      tmp = vm->ch[i];
      while (tmp)
	{
	  liveactual += tmp->live;
	  tmp->live = 0;
	  tmp = tmp->next;
	}
      if (liveactual == 0)
	{
	  dead++;
	  free_list(vm->ch[i]);
	  vm->ch[i] = NULL;
	}
    }
  return (dead);
}

void		free_list(t_champ *champ)
{
  t_champ	*tmp;
  t_champ	*tmp2;

  tmp = NULL;
  if (champ != NULL)
    tmp = champ->next;
  if (tmp != NULL)
    tmp2 = tmp->next;
  while (tmp != NULL)
    {
      if (tmp != NULL)
	free(tmp);
      tmp = tmp2;
      if (tmp2 != NULL)
	tmp2 = tmp2->next;
    }
}
