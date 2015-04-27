/*
** option.c for 103 architecte in /home/gicque_p/local/maths/103architecte
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 10 21:24:38 2013 Pierrick Gicquelais
** Last update Wed Dec 11 12:48:11 2013 Pierrick Gicquelais
*/

#include "architecte.h"

double	*check_option(double *resultat, double *matrice, char **argv, int argc)
{
  int	i;

  i = 3;
  while (i < argc)
    {
      if (argv[i][0] == 'T' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0' || argv[i + 2] == '\0')
            my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
          check_error_one(argv[i + 1]);
          check_error_one(argv[i + 2]);
          my_translation(&resultat[0], &matrice[0], argv, i);
          i = i + 3;
        }
      else if (argv[i][0] == 'H' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0' || argv[i + 2] == '\0')
            my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
          check_error_one(argv[i + 1]);
          check_error_one(argv[i + 2]);
          my_homothetie(&resultat[0], &matrice[0], argv, i);
          i = i + 3;
	}
      else if (argv[i][0] == 'R' && argv[i][1] == '\0')
	{
          if (argv[i + 1] == '\0')
            my_error("After option R or S, you must enter only one number\nExecute ./man_103 to read the man");
          check_error_two(argv[i + 1]);
          my_rotation(&resultat[0], &matrice[0], argv, i);
          i = i + 2;
        }
      else if (argv[i][0] == 'S' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0')
            my_error("After option R or S, you must enter only one number\nExecute ./man_103 to read the man");
          check_error_two(argv[i + 1]);
          my_symetrie(&resultat[0], &matrice[0], argv, i);
          i = i + 2;
        }
      else
        {
          printf("\033[01;31mWrong option. You can only enter options : T, H, R or S\nArgument number %d is not an option\nExecute ./man_103 to read the man\n", i);
          printf("\033[0;37m");
          exit (0);
        }
    }
  return (resultat);
}
