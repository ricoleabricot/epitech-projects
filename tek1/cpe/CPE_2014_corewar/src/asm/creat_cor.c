/*
** creat_cor.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Mar 24 14:38:29 2014 Christian Boisson
** Last update Sun Apr 13 20:15:39 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"op.h"
#include	"creat_cor.h"
#include	"asm.h"

void		write_cor(t_list *list, char **namecomm, int label_nbr)
{
  header_t	header;
  t_label	*label;
  int		total_size;
  int		fd;

  if ((label = malloc(sizeof(t_label) * (label_nbr + 1))) == NULL)
    exit(-1);
  total_size = comp_octet(list, label, 0);
  check_error(list, label);
  fd = my_get_champ_fd(namecomm[2]);
  header = name_comment(namecomm[0], namecomm[1]);
  header.magic = rev_int(COREWAR_EXEC_MAGIC);
  header.prog_size = rev_int(total_size);
  if (write(fd, &header, sizeof(header_t)) == -1)
    exit(-1);
  put_instruct(fd, list, label);
}

header_t	name_comment(char *name, char *comment)
{
  header_t	header;
  int		i;

  i = -1;
  while (name[++i])
    header.prog_name[i] = name[i];
  while (++i < PROG_NAME_LENGTH)
    header.prog_name[i] = '\0';
  i = -1;
  while (comment[++i])
    header.comment[i] = comment[i];
  while (++i < COMMENT_LENGTH)
    header.comment[i] = '\0';
  return (header);
}

int		rev_int(int nb)
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
