/*
** display.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb  4 21:40:07 2014 Pierrick Gicquelais
** Last update Fri Feb 14 11:07:50 2014 Pierrick Gicquelais
*/

#include		<term.h>
#include		<termios.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"../allum.h"

void			end_game(t_var *var)
{
  struct termios	t;

  if (tcgetattr(0, &t) == -1)
    my_error("Error with syscall tcgetattr");
  raw_attr(&t);
  tputs(tgetstr("vi", NULL), 1, my_putchar);
  tputs(tgoto(tgetstr("cm", NULL), 24, 4), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("+---------[REPLAY OR END]---------+\n");
  tputs(tgoto(tgetstr("cm", NULL), 24, 5), 1, my_putchar);
  my_putstr("|Would you like to replay Allum1 ?|\n\n");
  tputs(tgetstr("me", NULL), 1, my_putchar);
  choose_all(var, 3, 7, 8);
  canon_attr(&t);
  tputs(tgetstr("ve", NULL), 1, my_putchar);
  if (var->choice[3] == 1)
    {
      display_menu();
      my_choice();
    }
  else
    {
      tputs(tgetstr("cl", NULL), 1, my_putchar);
      exit(EXIT_SUCCESS);
    }
}

void			display_difficulty(t_var *var)
{
  tputs(tgoto(tgetstr("cm", NULL), 24, 17), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("+----------------[EASY OR HARDCORE]-----------------+\n");
  tputs(tgoto(tgetstr("cm", NULL), 24, 18), 1, my_putchar);
  my_putstr("|Would you like to play against an easy or hard AI ?|\n\n");
  tputs(tgetstr("me", NULL), 1, my_putchar);
  choose_all(var, 2, 20, 21);
}

void			display_pvp(t_var *var)
{
  tputs(tgoto(tgetstr("cm", NULL), 21, 12), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("+---------------------[AI OR PLAYER]----------------------+\n");
  tputs(tgoto(tgetstr("cm", NULL), 21, 13), 1, my_putchar);
  my_putstr("|Would you like to play against an AI or a second player ?|\n\n");
  tputs(tgetstr("me", NULL), 1, my_putchar);
  choose_all(var, 1, 15, 16);
}

void			display_mod(t_var *var)
{
  tputs(tgoto(tgetstr("cm", NULL), 32, 7), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("+------------[GAME MOD]------------+\n");
  tputs(tgoto(tgetstr("cm", NULL), 32, 8), 1, my_putchar);
  my_putstr("|Which mod would you like to play ?|\n\n");
  tputs(tgetstr("me", NULL), 1, my_putchar);
  choose_all(var, 0, 10, 11);
}

void			display_menu()
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  tputs(tgoto(tgetstr("cm", NULL), 25, 0), 1, my_putchar);
  my_putstr("_|_|_|_|  _|  _|                            _|_|");
  tputs(tgoto(tgetstr("cm", NULL), 25, 1), 1, my_putchar);
  my_putstr("_|    _|  _|  _|  _|    _|  _|_|_|  _|_|   _| _|");
  tputs(tgoto(tgetstr("cm", NULL), 25, 2), 1, my_putchar);
  tputs(tgetstr("md", NULL), 1, my_putchar);
  my_putstr("_|_|_|_|  _|  _|  _|    _|  _|    _|    _|    _|");
  tputs(tgoto(tgetstr("cm", NULL), 25, 3), 1, my_putchar);
  my_putstr("_|    _|  _|  _|  _|    _|  _|    _|    _|    _|");
  tputs(tgetstr("me", NULL), 1, my_putchar);
  tputs(tgoto(tgetstr("cm", NULL), 25, 4), 1, my_putchar);
  my_putstr("_|    _|  _|  _|  _|_|_|_|  _|    _|    _|    _|");
  tputs(tgetstr("me", NULL), 1, my_putchar);
}
