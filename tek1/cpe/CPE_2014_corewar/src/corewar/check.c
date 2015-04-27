/*
** check.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar 20 09:34:07 2014 Pierrick Gicquelais
** Last update Fri Apr 11 18:11:42 2014 Nicolas Ribeiro Teixeira
*/

#include	<sys/types.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"funct.h"
#include	"struct.h"
#include	"lib.h"

void		check_arg(int argc)
{
  if (argc < 2)
    {
      my_printf("Usage: ./corewar [-dump nbr_cycle] ");
      my_printf("[[-n prog_number] [-a load_adress] [prog_name.cor]] ..\n");
      exit(EXIT_FAILURE);
    }
}

int		check_dump(t_vm *vm, char **argv)
{
  if (my_strncmp("-dump", argv[1], 5) == 0)
    {
      if (argv[2] && my_isnum(argv[2]) == 0)
        {
          vm->dump_nbr = my_getnbr(argv[2]);
          return (3);
	}
      else
        {
	  vm->dump_nbr = -1;
          return (2);
	}
    }
  vm->dump_nbr = -1;
  return (1);
}

static int	check_prog_nbr(t_vm *vm, char **argv, int i)
{
  static int	pos = 0;

  if (my_strncmp("-n", argv[i], 2) == 0)
    {
      i++;
      if (argv[i] && my_isnum(argv[i]) == 0)
	{
          if (pos > 0 && my_getnbr(argv[i]) == vm->info[pos - 1].prog_nbr)
	    my_print_error("You can't enter twice the same prog number !\n");
	  vm->info[pos].prog_nbr = my_getnbr(argv[i]);
	  pos++;
	  return (i + 1);
	}
    }
  vm->info[pos].prog_nbr = pos + 1;
  pos++;
  return (i);
}

static int	check_load_adress(t_vm *vm, char **argv, int i)
{
  static int	pos = 0;

  if (my_strncmp("-a", argv[i], 2) == 0)
    {
      i++;
      if (argv[i] && my_isnum(argv[i]) == 0 && my_isneg(argv[i]) != 0)
	{
	  vm->info[pos].load_adress = my_getnbr(argv[i]) % MEM_SIZE;
	  pos++;
	  return (i + 1);
        }
    }
  if (my_isneg(argv[i]) == 0)
    my_print_error("You can't enter a negative load adress !\n");
  vm->info[pos].load_adress = -1;
  pos++;
  return (i);
}

int		check_champ(t_vm *vm, int argc, char **argv, int i)
{
  int		flag;

  flag = 0;
  while (i < argc)
    {
      i = check_prog_nbr(vm, argv, i);
      i = check_load_adress(vm, argv, i);
      if (my_strlcmp(argv[i], ".cor", (my_strlen(argv[i]) - 4)) != 0)
	my_print_error							\
	  ("Argument n°%d -> '%s' is not a corewar executable\n", i, argv[i]);
      i++;
      flag++;
    }
  vm->champ_nbr = flag;
  if (flag < MIN_CHAMP)
    my_print_error							\
      ("You must enter at least 1 champion executable by the corewar\n");
  else if (flag > MAX_CHAMP)
    my_print_error							\
      ("You can't enter more than 4 champions executable by the corewar\n");
  return (0);
}
