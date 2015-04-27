/*
** main.c for corewar in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar 20 09:18:44 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:19:18 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"struct.h"
#include	"funct.h"
#include	"op_func.h"

int		main(int argc, char **argv)
{
  t_vm		*vm;
  int		i;

  if ((vm = malloc(sizeof(t_vm))) == NULL)
    my_print_error("Error with a memory allocation\n");
  if ((vm->arena = malloc(sizeof(t_vm))) == NULL)
    my_print_error("Error with a memory allocation\n");
  init_arena(vm->arena->arena, MEM_SIZE);
  check_arg(argc);
  i = check_dump(vm, argv);
  check_champ(vm, argc, argv, i);
  init_champs(vm);
  my_parsing(vm, argc, argv, i);
  init_mlx(vm);
  aff_grid(vm);
  my_hook(vm);
  corewar(vm);
  return (0);
}
