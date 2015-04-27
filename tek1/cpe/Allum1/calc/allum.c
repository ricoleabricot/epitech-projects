/*
** algo.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb  4 21:37:04 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:26:33 2014 Pierrick Gicquelais
*/

#include	<curses.h>
#include	<term.h>
#include	<termios.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void		algo_allum(t_var *var)
{
  int		total;
  int		choice;
  char		*s;

  total = 30;
  choice = 0;
  while (total >= 1)
    {
      display_allum(total);
      my_putstr("How many matches would you like to withdraw ?: ");
      while ((s = get_next_line(0)) == NULL);
      choice = my_getnbr(s);
      if ((choice == 1 || choice == 2 || choice == 3) && total - choice > 0)
	{
	  total -= choice;
	  display_number(choice);
	  total = intell_allum(var, total);
	}
      else
	display_error();
    }
  display_success();
  end_game(var);
}

void            pvp_allum(t_var *var)
{
  int           total;
  int           choice;
  int           i;

  i = 0;
  total = 30;
  my_getnick(var);
  while (total >= 1)
    {
      display_allum(total);
      choice = get_info\
	(var, " how many matches would you like to withdraw ?: ", i);
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      display_nb(choice, i, var->j1, var->j2);
      if (choice >= 1 && choice <= 3)
	{
	  total = check_nbr(total, choice, &i);
	  if (i % 2 == 0)
	    check_end(var, total, var->j2);
	  else
	    check_end(var, total, var->j1);
	}
      else
	display_error();
    }
}
