/*
** advanced_check.c for allum1 in /home/gicque_p/local/cpe/Allum1/choosing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb 12 20:57:07 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:09:19 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int             check_nbr(int total, int choice, int *i)
{
  if ((total - choice) < 1 || choice == 0)
    {
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      my_putstr("\033[01;31m");
      my_putstr("You can't withdraw so many matches !\n");
      my_putstr("\033[0m");
    }
  else
    {
      total -= choice;
      (*i)++;
    }
  return (total);
}

int             check_nb(t_var *f, int *line, int choice, int *i)
{
  int           total;

  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  if ((total - choice) < 1 || (*line - choice) < 0 || choice == 0)
    {
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      my_putstr("\033[01;31m");
      my_putstr("You can't withdraw so many matches !\n");
      my_putstr("\033[0m");
    }
  else
    {
      *line -= choice;
      (*i)++;
      if (f->choice[1] == 1)
	{
	  check_success(f);
	  if (f->choice[2] == 1)
	    easy_marienbad(f, total);
	  else
	    marienbad(f, total);
	}
    }
  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  return (total);
}
