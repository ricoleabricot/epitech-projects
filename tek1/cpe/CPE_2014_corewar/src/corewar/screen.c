/*
** screen.c for vm in /home/gicque_p/local/cpe/CPE_2014_corewar/src/corewar
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr 14 12:04:01 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:03:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"


int		gere_key(int keycode, t_vm *vm)
{
  if (keycode == END_KEY)
    {
      free(vm);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

int		gere_expose(t_ptr *ptr)
{
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  return (0);
}
void		my_hook(t_vm *vm)
{
  mlx_key_hook(vm->ptr->win_ptr, &gere_key, vm);
  mlx_expose_hook(vm->ptr->win_ptr, &gere_expose, vm->ptr);
  mlx_loop(vm->ptr->mlx_ptr);
}
