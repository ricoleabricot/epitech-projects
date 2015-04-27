/*
** aff.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select/string
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jan 16 19:38:01 2014 Pierrick Gicquelais
** Last update Thu Jan 16 19:38:51 2014 Pierrick Gicquelais
*/

#include	"../select.h"

void		aff_arg(t_list *list, int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    append_list(list, argv[i]);
  aff_list(list);
}
