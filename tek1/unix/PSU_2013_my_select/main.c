/*
** main.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 17:15:28 2014 Pierrick Gicquelais
** Last update Sun Jan 19 22:00:21 2014 Pierrick Gicquelais
*/

#include		<signal.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"select.h"

int			main(int argc, char **argv, char **envp)
{
  struct termios	t;
  t_list		*list;
  t_list		*list_final;

  if (argc < 2)
    my_error("You must enter at least one argument");
  if (tgetent(NULL, find_term(envp)) == -1)
    my_error("Error with syscall tgetent");
  free(find_term(envp));
  list = init_list();
  list_final = init_list();
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  aff_arg(list, argc, argv);
  if (tcgetattr(0, &t) == -1)
    my_error("Error with syscall tcgetattr");
  raw_attr(&t);
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
  my_choice(&t, list, list_final);
  return (0);
}
