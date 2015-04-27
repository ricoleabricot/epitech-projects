/*
** launch.c for allum in /home/gicque_p/local/cpe/Allum1/choosing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Feb  6 14:04:41 2014 Pierrick Gicquelais
** Last update Wed Feb 12 22:26:07 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void		launch_game(t_var *var)
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  if (var->choice[0] == 1 && var->choice[1] == 1)
    algo_allum(var);
  else if (var->choice[0] == 1 && var->choice[1] == 2)
    pvp_allum(var);
  else if (var->choice[0] == 2 && var->choice[1] == 1)
    algo_nim(var);
  else if (var->choice[0] == 2 && var->choice[1] == 2)
    pvp_nim(var);
}
