/*
** main.c for 103architecte in /home/gicque_p/local/maths/103architecte
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec  9 09:38:37 2013 Pierrick Gicquelais
** Last update Thu Dec 12 13:40:08 2013 Pierrick Gicquelais
*/

#include "architecte.h"

int	main(int argc, char **argv)
{
  double	matrice[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  double	resultat[3];

  if (argc < 5)
    my_error("Too few arguments. Must enter 5 arguments minimum\nExecute ./man_103 to read the man");
  resultat[0] = atof(argv[1]);
  resultat[1] = atof(argv[2]);
  resultat[2] = 1;
  check_option(resultat, matrice, argv, argc);
  aff_mat(matrice);
  printf("(%s, %s) => (%.3f, %.3f)\n", argv[1], argv[2], resultat[0], resultat[1]);
  printf("\033[0;37m");
  return (0);
}
