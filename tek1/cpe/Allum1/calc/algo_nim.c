/*
** algo_nim.c for allum1 in /home/gicque_p/local/cpe/Allum1/calc
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Wed Feb 12 11:41:44 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:28:43 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int		my_allow(t_var *f, int total, int choice_line, int *i)
{
  char		*s;
  int		choice;

  my_putstr("How many matches would you like to withdraw ?: ");
  while ((s = get_next_line(0)) == NULL);
  choice = my_getnbr(s);
  display_number(choice);
  if (choice_line == 1)
    total = check_nb(f, &f->line[0], choice, i);
  else if (choice_line == 2)
    total = check_nb(f, &f->line[1], choice, i);
  else if (choice_line == 3)
    total = check_nb(f, &f->line[2], choice, i);
  else if (choice_line == 4)
    total = check_nb(f, &f->line[3], choice, i);
  return (total);
}

void		algo_nim(t_var *f)
{
  char		*s;
  int		total;
  int		choice_line;
  int		i;

  init_nim(f);
  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  i = 0;
  while (total > 1)
    {
      display_nim(f->line[0], f->line[1], f->line[2], f->line[3]);
      my_putstr("On which line would yuo like to withdraw matches ?: ");
      while ((s = get_next_line(0)) == NULL);
      choice_line = my_getnbr(s);
      if (choice_line >= 1 && choice_line <= 4)
	total = my_allow(f, total, choice_line, &i);
      else
	{
	  tputs(tgetstr("cl", NULL), 1, my_putchar);
	  my_putstr("\033[01;31mThis line doesn't exist !\n\033[0m");
	}
    }
  ending_intell(f, total);
  end_game(f);
  exit(EXIT_SUCCESS);
}
