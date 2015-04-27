/*
** main.c for 101pong in /home/gicque_p/local/maths/101pong
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Nov  9 13:25:09 2013 Pierrick Gicquelais
** Last update Thu Nov 14 14:58:48 2013 Pierrick Gicquelais
*/

#include "main.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	*speed_vector(int *tab, int argc, char **argv)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (i < argc)
    {
      if (my_str_isnum(argv[i]) == 0)
	{
	  printf("Argument %d is not a number\n", i);
	  exit (0);
	}
      tab[j] = my_getnbr(argv[i]);
      if (tab[j] < -2147483647 || tab[j] > 2147483647)
	{
	  printf("Argument %d is not contained in an int\n", i);
	  printf("Argument must be higher '-2147483647' or under '2147483647'\n");
	  exit (0);
	}
      j++;
      i++;
    }
  return (tab);
}

int	*pos_coord(int *tab, int *tab2, int position)
{
  int	cmp;

  cmp = 0;
  tab2[0] = tab[3];
  tab2[1] = tab[4];
  tab2[2] = tab[5];
  while (cmp < position)
    {
      tab2[0] = tab2[0] + (tab[3] - tab[0]);
      tab2[1] = tab2[1] + (tab[4] - tab[1]);
      tab2[2] = tab2[2] + (tab[5] - tab[2]);
      cmp++;
    }
  return (tab2);
}

float	scalaire_prod(int *tab)
{
  float	resultat;
  
  resultat = sqrt(pow(-(tab[4] - tab[1]), 2) + pow((tab[3] - tab[0]), 2));
  if (resultat == 0)
    return (0);
  resultat = resultat / sqrt(pow((tab[3] - tab[0]), 2) + pow((tab[4] - tab[1]), 2) + pow((tab[5] - tab[2]), 2));
  return(acos(resultat) * 57.295779);
}

int	main(int argc, char **argv)
{
  int	tab[6];
  int	tab2[3];
  float	angle;

  angle = 0;
  if (argc != 8)
    {
      my_putstr("Wrong number of arguments. Must be 7\n");
      return (0);
    }
  if (my_getnbr(argv[7]) < 0)
    {
      my_putstr("Argument 7 must be positive or null\n");
      return (0);
    }
  speed_vector(tab, argc, argv);
  printf("Les coordonnées du vecteur vitesse sont (%d;%d;%d).\n", tab[3] - tab[0], tab[4] - tab[1], tab[5] - tab[2]);

  pos_coord(tab, tab2, my_getnbr(argv[7]));
  printf("A l'instant t+%d, les coordonnées de la balle seront (%d;%d;%d).\n", my_getnbr(argv[7]), tab2[0], tab2[1], tab2[2]);

  angle = scalaire_prod(tab);
  printf("L'angle d'incidence est de %.2f degrés.\n", angle);
  return (0);
}
