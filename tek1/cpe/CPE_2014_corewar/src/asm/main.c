/*
** main.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
**
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
**
** Started on Thu Mar 20 14:08:32 2014 Nicolas Ribeiro Teixeira
** Last update Fri Apr 11 14:29:50 2014 Nicolas Ribeiro Teixeira
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"lib.h"
#include	"op.h"
#include	"asm.h"

char		**get_namecomm(char *name, char *comment, char *filename)
{
  char		**namecomm;

  if ((namecomm = malloc(sizeof(char *) * 4)) == NULL)
    exit(0);
  namecomm[0] = name;
  namecomm[1] = comment;
  namecomm[2] = filename;
  namecomm[3] = NULL;
  return (namecomm);
}

void		launch_asm(int dotsfd, char *filename, t_list *begin)
{
  char		*s;
  char		*name;
  char		*comment;
  char		**namecomm;
  int		line_nbr;
  int		label_nbr;

  label_nbr = 0;
  line_nbr = 1;
  if ((name = my_get_name(dotsfd, &line_nbr, 0, 0)) == NULL)
    my_error(5, "No name found", 0, NULL);
  if ((comment = my_get_comment(dotsfd, &line_nbr, 0, 0)) == NULL)
    my_error(5, "No comment found", 0, NULL);
  while ((s = my_one_get_next_line(dotsfd)) != NULL)
    {
      if (s[0] != COMMENT_CHAR && s[0] != '\0' && empty_str(s)
	  && spec_case(s, &begin, line_nbr, &label_nbr))
	begin = my_append_instruction(begin, s, &label_nbr, line_nbr);
      free(s);
      line_nbr++;
    }
  begin = parse_chained_list(begin);
  namecomm = get_namecomm(name, comment, filename);
  close(dotsfd);
  write_cor(begin, namecomm, label_nbr);
}

int		my_get_dotsfd(char *name)
{
  int		len;
  int		dotsfd;

  len = my_strlen(name);
  my_check_name(name, len);
  dotsfd = open(name, O_RDONLY);
  if (dotsfd == -1)
    {
      my_putstr("File ");
      my_putstr(name);
      my_putstr(" not accessible\n");
      exit(1);
    }
  return (dotsfd);
}

int		main(int ac, char **av)
{
  int		dotsfd;

  if (ac == 2)
    {
      dotsfd = my_get_dotsfd(av[1]);
      launch_asm(dotsfd, av[1], NULL);
    }
  else
    my_putstr("[USAGE] : ./asm [CHAMPION_FILENAME.s]\n");
  return (0);
}
