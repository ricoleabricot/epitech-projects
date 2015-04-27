/*
** check.c for allum in /home/gicque_p/local/cpe/Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb  5 21:40:46 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:27:20 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void		next_option(t_var *var, int option)
{
  if (option == 2)
    {
      my_putstr("--> ");
      tputs(tgetstr("md", NULL), 1, my_putchar);
      tputs(tgetstr("us", NULL), 1, my_putchar);
      my_putstr("Easy AI\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      my_putstr("Hardcore AI\n");
      var->s1 = "Easy AI";
      var->s2 = "Hardcore AI";
    }
  else if (option == 3)
    {
      my_putstr("--> ");
      tputs(tgetstr("md", NULL), 1, my_putchar);
      tputs(tgetstr("us", NULL), 1, my_putchar);
      my_putstr("Replay the Game\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      my_putstr("End the Game\n");
      var->s1 = "Replay the Game";
      var->s2 = "End the Game";
    }
}

void		check_option(t_var *var, int option)
{
  if (option == 0)
    {
      my_putstr("--> ");
      tputs(tgetstr("md", NULL), 1, my_putchar);
      tputs(tgetstr("us", NULL), 1, my_putchar);
      my_putstr("Matches Game\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      my_putstr("Nim's Game\n");
      var->s1 = "Matches Game";
      var->s2 = "Nim's Game";
    }
  else if (option == 1)
    {
      my_putstr("--> ");
      tputs(tgetstr("md", NULL), 1, my_putchar);
      tputs(tgetstr("us", NULL), 1, my_putchar);
      my_putstr("Player versus AI\n");
      tputs(tgetstr("me", NULL), 1, my_putchar);
      my_putstr("Player versus Player\n");
      var->s1 = "Player versus AI";
      var->s2 = "Player versus Player";
    }
  next_option(var, option);
}

void		useless_check(int argc, char **argv)
{
  if (argc > 1)
    my_error("You don't have to enter arguments");
  if (argv[1])
    my_error("Oh, you have entered an argument ! ..");
}
