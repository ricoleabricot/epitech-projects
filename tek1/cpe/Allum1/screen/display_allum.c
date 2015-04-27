/*
** display_pvp.c for allum1 in /home/gicque_p/local/cpe/Allum1/screen
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Sat Feb  8 01:18:47 2014 Pierrick Gicquelais
** Last update Fri Feb 14 11:53:42 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void            display_success()
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("The AI withdraws the last matche\n");
  my_putstr("You won, well done !\n");
  tputs(tgetstr("me", NULL), 1, my_putchar);
}

void            display_error()
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  my_putstr("\033[01;31m");
  my_putstr("You can only withdraw between 1 or 3 matches !\n");
  my_putstr("\033[0m");
}

void            display_number(int choice)
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  my_putstr("You withdraw ");
  my_putnbr(choice);
  my_putstr(" matche(s)\n");
}

void            display_allum(int total)
{
  int           i;

  i = 0;
  my_putstr("There are ");
  my_putnbr(total);
  my_putstr(" matches on the plate\n\n");
  while (i++ < total)
    {
      tputs(tgoto(tgetstr("cm", NULL), i + 1, 5), 1, my_putchar);
      my_putstr("\033[01;31mo\033[0m");
      tputs(tgoto(tgetstr("cm", NULL), i + 1, 6), 1, my_putchar);
      my_putstr("|");
    }
  my_putstr("\n\n");
}

void            display_nb(int choice, int i, char *j1, char *j2)
{
  if (i % 2 == 0)
    my_putstr(j1);
  else
    my_putstr(j2);
  my_putstr(" withdraws ");
  my_putnbr(choice);
  my_putstr(" matche(s)\n");
}
