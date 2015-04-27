/*
** matrice.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Nov 26 16:37:31 2013 Pierrick Gicquelais
** Last update Sat Nov 30 12:58:29 2013 Pierrick Gicquelais
*/

#include "main.h"

void    matrice_prod(int *tab, int nb, char **argv)
{
  int   i;
  int   j;
  int   tab2[nb];

  i = 0;
  j = 0;
  my_putstr("=> ");
  if (nb % 2 != 0)
    {
      while (i < nb + 1)
        {
          tab2[j] = (tab[i] * atoi(argv[2])) + (tab[i + 1] * atoi(argv[4]));
          tab2[j + 1] = (tab[i] * atoi(argv[3])) + (tab[i + 1] * atoi(argv[5]));
	  convert_base(tab2[j], argv[6]);
	  my_putchar(' ');
          convert_base(tab2[j + 1], argv[6]);
          my_putchar(' ');
          i = i + 2;
          j = j + 2;
        }
    }
  else
    {
      while (i < nb)
        {
          tab2[j] = (tab[i] * atoi(argv[2])) + (tab[i + 1] * atoi(argv[4]));
          tab2[j + 1] = (tab[i] * atoi(argv[3])) + (tab[i + 1] * atoi(argv[5]));
          convert_base(tab2[j], argv[6]);
          my_putchar(' ');
          convert_base(tab2[j + 1], argv[6]);
          my_putchar(' ');
          i = i + 2;
          j = j + 2;
        }
    }
}

int	*inverse_matrice(char **argv)
{
  int	determinant;
  int	*tab;

  tab = malloc(4 * sizeof(int));
  determinant = (atoi(argv[2]) * atoi(argv[5])) - (atoi(argv[3]) * atoi(argv[4]));
  if (determinant == 0)
    {
      printf("\033[01;33mMatrice not reversible.\n\033[0;37m");
      exit (0);
    }
  tab[0] = (1 / determinant) * atoi(argv[5]);
  tab[1] = (1 / determinant) * (-(atoi(argv[4])));
  tab[2] = (1 / determinant) * (-(atoi(argv[3])));
  tab[3] = (1 / determinant) * atoi(argv[2]);
  return (tab);
}
