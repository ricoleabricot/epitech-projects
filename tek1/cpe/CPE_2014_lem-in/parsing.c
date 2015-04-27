/*
** parsing.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 17 11:21:06 2014 Pierrick Gicquelais
** Last update Fri Apr 18 12:03:40 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"macro.h"
#include	"funct.h"

void		check_label(char *s, int *flag)
{
  if (strcmp(s, START_LABEL) == 0)
    {
      my_fputstr(1, "Je suis passé dans un START !\n");
      (*flag)++;
    }
  else if (strcmp(s, END_LABEL) == 0)
    {
      my_fputstr(1, "Je suis passé dans un END !\n");
      (*flag)++;
    }
}

void		check_comment(char *s)
{
  if (s[0] && s[0] == COMMENT_CHAR && s[1] && s[1] != COMMENT_CHAR)
    my_fputstr(1, "Je suis dans un COMMENT !\n");
}

void		my_parsing(t_graf *graf)
{
  char		*s;
  int		flag;
  int		nb_fourmi;

  nb_fourmi = 0;
  if ((s = get_next_line(0)))
    nb_fourmi = atoi(s);
  free(s);
  flag = 0;
  while ((s = get_next_line(0)))
    {
      s = epur_str(s);
      my_fputstr(1, s);
      my_fputchar(1, '\n');
      check_comment(s);
      check_label(s, &flag);
      free(s);
    }
  free(s);
  if (flag == 2)
    my_fputstr(1, "Il y a un start et un end, bonne map !\n");
  else {
    my_fputstr(2, "Error, no end or no start !\n"); exit(EXIT_FAILURE); }
  printf("Fini, nb fourmis: %d, sommet: %d\n", nb_fourmi, graf->sommet);
}
