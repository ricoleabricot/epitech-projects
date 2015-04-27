/*
** parsing.c for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Mar 25 12:03:45 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:16:57 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"struct.h"
#include	"funct.h"

int		reverse_bit(int nb)
{
  int		oct_a;
  int		oct_b;
  int		oct_c;
  int		oct_d;

  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0xFF;
  oct_c = (nb >> 16) & 0xFF;
  oct_d = (nb >> 24) & 0xFF;
  return (oct_a * 16777216 + oct_b * 65536 + oct_c * 256 + oct_d);
}

static void	fill_champ(t_info *info, char *name, char *comment)
{
  int		i;

  i = -1;
  while (name[++i])
    info->name[i] = name[i];
  info->name[i] = 0;
  i = -1;
  while (comment[++i])
    info->comment[i] = comment[i];
  info->comment[i] = 0;
}

static void	fill_arena(t_vm *vm, int fd, int nbr)
{
  int		size;
  int		i;
  char		buf[1];
  int		value;

  if (vm->info[nbr - 1].load_adress == -1)
    {
      value = MEM_SIZE / vm->champ_nbr;
      vm->info[nbr - 1].load_adress = value * nbr - value / 2 - \
	(vm->info[nbr -1].prog_size / 2);
    }
  i = vm->info[nbr - 1].load_adress;
  while ((size = read(fd, buf, 1)) > 0)
    {
      if (vm->arena->arena[i] != 0)
	{
	  my_printf("Check load adresses, ");
	  my_printf("champion n°%d (%s) is writting on a champion ", \
		    vm->info[nbr - 1].prog_nbr, vm->info[nbr - 1].name);
	  my_print_error("at adress %d !\n", i);
	}
      vm->arena->arena[i] = buf[0];
      vm->arena->block = i;
      vm->arena->player = nbr;
      my_fill_image(vm);
      i++;
    }
}

static int	read_header(t_info *info, char *file, int nbr)
{
  t_header	header;
  int		fd;
  int		size;

  info->pos = nbr;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_print_error("Cannot open file: %s. Make sure the file exists\n", file);
  if ((size = read(fd, &header, sizeof(t_header))) == 0)
    my_print_error("Cannot read the file %s. The file is empty\n", file);
  header.magic = reverse_bit(header.magic);
  header.prog_size = reverse_bit(header.prog_size);
  if (header.magic != COREWAR_EXEC_MAGIC)
    my_print_error("Wrong magic number for champion n°%d\n", nbr);
  else if (header.prog_size > PROG_SIZE_MAX)
    my_print_error("Prog size for champion n°%d too high\n", nbr);
  info->prog_size = header.prog_size;
  fill_champ(info, header.prog_name, header.comment);
  return (fd);
}

int             my_parsing(t_vm *vm, int argc, char **argv, int i)
{
  int           nbr;
  int		fd;

  nbr = 1;
  while (i < argc)
    {
      if (my_strlcmp(argv[i], ".cor", (my_strlen(argv[i]) - 4)) == 0)
	{
	  fd = read_header(&vm->info[nbr - 1], argv[i], nbr);
	  fill_arena(vm, fd, nbr);
	  nbr++;
	  close(fd);
	}
      i++;
    }
  return (0);
}
