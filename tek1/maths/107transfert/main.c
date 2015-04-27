/*
** main.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 24 21:11:03 2014 Pierrick Gicquelais
** Last update Fri Mar  7 18:10:33 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

int		main(int argc, char **argv, char **envp)
{
  if (check_env(envp) == 0)
    env_error();
  if (argc < 2)
    argc_error();
  else if (argc == 2)
    ex1(argv[1]);
  else
    ex2(argc - 1, argv);
  return (0);
}
