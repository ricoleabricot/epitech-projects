/*
** check_allum.c for allum1 in /home/gicque_p/local/cpe/Allum1/choosing
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Sat Feb  8 01:21:32 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:26:06 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void		check_success(t_var *f)
{
  if (f->line[0] + f->line[1] + f->line[2] + f->line[3] == 1)
    {
      display_success();
      end_game(f);
    }
}

void            check_end(t_var *var, int total, char *name)
{
  if (total == 1)
    {
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      tputs(tgetstr("md", NULL), 1, my_putchar);
      my_putstr("There is only one matche on the plate\n");
      my_putstr(name);
      my_putstr(" won, well done !\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      end_game(var);
    }
}

void		check_name(char *j1, char *j2)
{
  if (my_strlen(j1) > 15)
    my_error("Player 1 got a too long nickname (max 15)");
  if (my_strlen(j2) > 15)
    my_error("Player 2 got a too long nickname (max 15)");
}
