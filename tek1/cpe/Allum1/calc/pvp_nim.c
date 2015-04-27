/*
** nim.c for allum1 in /home/gicque_p/local/cpe/Allum1/calc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Feb  9 12:09:14 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:26:17 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int		allow_choice(t_var *f, int total, int choice_line, int *i)
{
  int		choice;

  choice = get_info						\
    (f, ": how many matches would you like to withdraw ?: ", *i);
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  display_nb(choice, *i, f->j1, f->j2);
  if (choice_line == 1)
    total = check_nb(f, &f->line[0], choice, i);
  else if (choice_line == 2)
    total = check_nb(f, &f->line[1], choice, i);
  else if (choice_line == 3)
    total = check_nb(f, &f->line[2], choice, i);
  else if (choice_line == 4)
    total = check_nb(f, &f->line[3], choice, i);
  if (*i % 2 == 0)
    check_end(f, total, f->j2);
  else
    check_end(f, total, f->j1);
  return (total);
}

void		init_nim(t_var *f)
{
  f->line[0] = 1;
  f->line[1] = 3;
  f->line[2] = 5;
  f->line[3] = 7;
  if (f->choice[1] == 2)
    my_getnick(f);
}

void		pvp_nim(t_var *f)
{
  int		total;
  int		choice_line;
  int		i;

  init_nim(f);
  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  i = 0;
  while (total >= 1)
    {
      display_nim(f->line[0], f->line[1], f->line[2], f->line[3]);
      choice_line = get_info					\
	(f, " on which line woud you like to withdraw matches?: ", i);
      if (choice_line >= 1 && choice_line <= 4)
	allow_choice(f, total, choice_line, &i);
      else
	{
	  tputs(tgetstr("cl", NULL), 1, my_putchar);
	  my_putstr("\033[01;31mThis line doesn't exist !\n\033[0m");
	}
    }
}
