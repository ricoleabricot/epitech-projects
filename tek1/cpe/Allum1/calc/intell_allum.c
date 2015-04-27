/*
** intel.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  3 23:35:17 2014 Pierrick Gicquelais
** Last update Fri Feb 14 11:59:55 2014 Pierrick Gicquelais
*/

#include	<time.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int		random_intell(t_var *var, int total)
{
  int		hasard;

  srand(time(0));
  hasard = 1 + rand()%3;
  if (var->choice[2] == 1)
    {
      if (total == 4)
	hasard = 2;
      else if (total == 3)
	hasard = 1;
      else if (total == 2)
	hasard = 1;
    }
  total -= hasard;
  my_putstr("The AI withdraws ");
  my_putnbr(hasard);
  my_putstr(" matche(s)\n");
  return (total);
}

void		ending_intell(t_var *var, int total)
{
  if (total == 1 || total == 0)
    {
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      tputs(tgetstr("md", NULL), 1, my_putchar);
      my_putstr("There is only one matche on the plate\n");
      my_putstr("You loose, too bad !\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      end_game(var);
    }
}

int		intell_withdraw(t_var *var, int total)
{
  if ((total - 1) % 4 == 1)
    {
      total -= 1;
      my_putstr("The AI withdraws 1 matche\n");
    }
  else if ((total - 2) % 4 == 1)
    {
      total -= 2;
      my_putstr("The AI withdraws 2 matches\n");
    }
  else if ((total - 3) % 4 == 1)
    {
      total -= 3;
      my_putstr("The AI withdraws 3 matches\n");
    }
  else
    total = random_intell(var, total);
  return (total);
}

int		intell_allum(t_var *var, int total)
{
  my_putstr("AI is playing ...\n");
  sleep(1);
  if (var->choice[2] == 1)
    total = random_intell(var, total);
  else
    total = intell_withdraw(var, total);
  ending_intell(var, total);
  return (total);
}
