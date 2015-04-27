/*
** test.c for bombyx in /home/gicque_p/local/maths/106bombyx
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Feb 10 10:34:36 2014 Pierrick Gicquelais
** Last update Sat Feb 15 11:58:20 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

int		main(int argc, char **argv)
{
  t_bomb	*bomb;

  if ((bomb = malloc(sizeof(t_bomb))) == NULL)
    exit(0);
  my_init(bomb);
  if (argc == 2)
    fill_ex1(bomb, argv[1]);
  else if (argc == 3)
    fill_ex2(bomb, argv[1], argv[2]);
  else
    my_error("Error 20: You must enter only one or two arguments", 20);
  my_hook(bomb);
  return (0);
}
