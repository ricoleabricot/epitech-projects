/*
** main.c for pushswap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec 16 12:49:09 2013 Pierrick Gicquelais
** Last update Mon Jan  6 21:30:00 2014 Pierrick Gicquelais
*/

#include	"push.h"

int		main(int argc, char **argv)
{
  t_list	*l_a;
  t_list	*l_b;
  int		i;

  i = first_sort(argc, argv);
  l_a = init_list();
  l_b = init_list();
  while (i < argc)
    append_list(l_a, my_getnbr(argv[i++]));
  if (my_strcmp(argv[1], "-d") == 0 || my_strcmp(argv[2], "-d") == 0)
    sort_list_inverse(l_a, l_b, argv);
  else
    sort_list(l_a, l_b, argv);
  if (my_strcmp(argv[1], "-a") == 0 || my_strcmp(argv[2], "-a") == 0)
    {
      my_putchar('\n');
      my_putstr("Sorted list : ");
      aff_list(l_a);
    }
  my_putchar('\n');
  return (0);
}
