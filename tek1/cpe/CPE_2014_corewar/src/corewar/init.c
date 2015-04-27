/*
** init.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 11 20:05:14 2014 Pierrick Gicquelais
** Last update Mon Apr 14 11:54:16 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"struct.h"
#include	"funct.h"
#include	"op_func.h"

void		init_mlx(t_vm *vm)
{
  if ((vm->ptr = malloc(sizeof(t_ptr))) == NULL)
    my_print_error("Error with a memory allocation\n");
  if ((vm->ptr->mlx_ptr = mlx_init()) == NULL)
    my_print_error("Environment disabled. End of programm\n");
  vm->ptr->img_ptr = mlx_new_image(vm->ptr->mlx_ptr, WIN_X, WIN_Y);
  vm->ptr->data = mlx_get_data_addr\
    (vm->ptr->img_ptr, &(vm->ptr->bpp), &(vm->ptr->sizeline), &(vm->ptr->endian));
  vm->ptr->win_ptr = mlx_new_window\
    (vm->ptr->mlx_ptr, WIN_X, WIN_Y, "CoreWarlords of Draenor");
  mlx_put_image_to_window(vm->ptr->mlx_ptr, vm->ptr->win_ptr, vm->ptr->img_ptr, 0, 0);
}

void		init_pc(t_vm *vm)
{
  int		i;

  i = 0;
  while (i < vm->champ_nbr)
    {
      vm->ch[i]->pc = vm->info[i].load_adress;
      i++;
    }
}

void		init_arena(unsigned char arena[], int size)
 {
   int		i;

   i = 0;
  while (i < size)
     {
       arena[i] = 0;
       i++;
     }
}

void		init_reg(t_champ *ch, t_info *info)
{
  int           i;

  ch->reg[0] = info->prog_nbr;
  i = 1;
  while (i != REG_NUMBER)
    {
      ch->reg[i] = 0;
      i++;
    }
}

void		init_champs(t_vm *vm)
{
  int		i;

  i = 0;
  if ((vm->ch = malloc(sizeof(t_champ *) * vm->champ_nbr)) == NULL)
    exit(0);
  while (i != vm->champ_nbr)
    {
      if ((vm->ch[i] = malloc(sizeof(t_champ))) == NULL)
        exit(0);
      if ((vm->ch[i]->instru = malloc(sizeof(t_instru))) == NULL)
	exit(0);
      vm->ch[i]->instru->exec_cycle = -1;
      vm->ch[i]->live = 0;
      i++;
    }
}
