/*
** main.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Nov 24 17:36:16 2013 Pierrick Gicquelais
** Last update Tue Nov 26 16:48:51 2013 Pierrick Gicquelais
*/

#include "main.h"

int	main(int argc, char **argv)
{
  my_list_error(argc, argv);
  my_list_error_next(argv);
  if (argv[7][0] == '0')
    my_encode(argv);
  if (argv[7][0] == '1')
    my_decode(argv);
  printf("\n");
  return (0);
}
