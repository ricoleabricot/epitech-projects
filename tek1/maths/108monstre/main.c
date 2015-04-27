/*
** main.c for 108monstre in /home/gicque_p/local/maths/108monstre
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 10 08:49:51 2014 Pierrick Gicquelais
** Last update Mon Mar 17 17:00:23 2014 Pierrick Gicquelais
*/

#include	"monstre.h"

int		main(int argc, char **argv, char **envp)
{
  if (argc != 3)
    argc_error(argc - 1);
  else if (my_strisnum(argv[1]) == 1)
    string_error(1);
  else if (my_strisnum(argv[2]) == 1)
    string_error(2);
  else if (atof(argv[1]) <= 2)
    first_arg_error();
  else if (atof(argv[2]) < 0)
    second_arg_error();
  execve("./python", argv, envp);
  return (0);
}
