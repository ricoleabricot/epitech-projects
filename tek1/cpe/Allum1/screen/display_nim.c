/*
** display_nim.c for allum1 in /home/gicque_p/local/cpe/Allum1/screen
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Feb  9 18:32:53 2014 Pierrick Gicquelais
** Last update Fri Feb 14 11:53:14 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void            display_line()
{
  tputs(tgoto(tgetstr("cm", NULL), 0, 4), 1, my_putchar);
  my_putstr("1) \n\n");
  tputs(tgoto(tgetstr("cm", NULL), 0, 7), 1, my_putchar);
  my_putstr("2) \n\n");
  tputs(tgoto(tgetstr("cm", NULL), 0, 10), 1, my_putchar);
  my_putstr("3) \n\n");
  tputs(tgoto(tgetstr("cm", NULL), 0, 13), 1, my_putchar);
  my_putstr("4) \n\n");
}

void            display_each_line(int i, int beg, int end)
{
  tputs(tgoto(tgetstr("cm", NULL), i, beg), 1, my_putchar);
  my_putstr("\033[01;31mo\033[0m");
  tputs(tgoto(tgetstr("cm", NULL), i, end), 1, my_putchar);
  my_putstr("|");
}

void		display_total_line(int l1, int l2, int l3, int l4)
{
  tputs(tgoto(tgetstr("cm", NULL), 25, 4), 1, my_putchar);
  my_putstr("[Total matches: ");
  my_putnbr(l1);
  my_putstr("]");
  tputs(tgoto(tgetstr("cm", NULL), 25, 7), 1, my_putchar);
  my_putstr("[Total matches: ");
  my_putnbr(l2);
  my_putstr("]");
  tputs(tgoto(tgetstr("cm", NULL), 25, 10), 1, my_putchar);
  my_putstr("[Total matches: ");
  my_putnbr(l3);
  my_putstr("]");
  tputs(tgoto(tgetstr("cm", NULL), 25, 13), 1, my_putchar);
  my_putstr("[Total matches: ");
  my_putnbr(l4);
  my_putstr("]");
}

void            display_nim(int l1, int l2, int l3, int l4)
{
  int           i;

  i = 0;
  display_line();
  while (i++ < l1)
    display_each_line(i + 7, 3, 4);
  i = 0;
  while (i++ < l2)
    display_each_line(i + 6, 6, 7);
  i = 0;
  while (i++ < l3)
    display_each_line(i + 5, 9, 10);
  i = 0;
  while (i++ < l4)
    display_each_line(i + 4, 12, 13);
  display_total_line(l1, l2, l3, l4);
  my_putstr("\n\n");
  tputs(tgoto(tgetstr("cm", NULL), 0, 15), 1, my_putchar);
}
