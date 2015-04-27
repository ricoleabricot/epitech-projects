/*
** main.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  3 21:14:02 2014 Pierrick Gicquelais
** Last update Fri Feb 14 11:43:57 2014 Pierrick Gicquelais
*/

#include	<term.h>
#include	<termios.h>
#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"allum.h"

int		main(int argc, char **argv, char **envp)
{
  char		*env;

  env = find_term(envp);
  useless_check(argc, argv);
  if (tgetent(NULL, env) == -1)
    my_error("Error with syscall tgetent");
  free(env);
  display_menu();
  my_choice();
  return (0);
}
