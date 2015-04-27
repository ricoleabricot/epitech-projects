/*
** option.c for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 09:37:03 2014 Pierrick Gicquelais
** Last update Fri Jan 17 15:34:04 2014 Pierrick Gicquelais
*/

#include	"tore.h"

void		bissection_choice(char **argv)
{
  double	x4;
  double	x3;
  double	x2;
  double	x1;
  double	x0;
  double	pt1;
  double	pt2;

  pt1 = 0;
  pt2 = 1;
  x4 = atoi(argv[6]);
  x3 = atoi(argv[5]);
  x2 = atoi(argv[4]);
  x1 = atoi(argv[3]);
  x0 = atoi(argv[2]);
  printf("Méthode de la bissection\n");
  printf("Point initial 1: %.f\n", pt1);
  printf("Point initial 2: %.f\n", pt2);
  aff_bissection(x4, x3, x2, x1, x0, pt1, pt2, argv);
  printf("Number of iterations too high. Convergeance doesn't reached\n");
}

void		newton_choice(char **argv)
{
  double	x4;
  double	x3;
  double	x2;
  double	x1;
  double	x0;
  double	xn1;

  x4 = atoi(argv[6]);
  x3 = atoi(argv[5]);
  x2 = atoi(argv[4]);
  x1 = atoi(argv[3]);
  x0 = atoi(argv[2]);
  xn1 = 0.5;
  printf("Méthode de Newton\n");
  printf("Point initial: 0.5\n");
  aff_newton(x4, x3, x2, x1, x0, xn1, argv);
  printf("Number of iterations too high. Convergeance doesn't reached\n");
}

void		secante_choice(char **argv)
{
  double	x4;
  double	x3;
  double	x2;
  double	x1;
  double	x0;
  double	pt1;
  double	pt2;

  pt1 = 0.4;
  pt2 = 0.8;
  x4 = atoi(argv[6]);
  x3 = atoi(argv[5]);
  x2 = atoi(argv[4]);
  x1 = atoi(argv[3]);
  x0 = atoi(argv[2]);
  printf("Méthode de la sécante\n");
  printf("Point initial 1: %.f\n", pt1);
  printf("Point initial 2: %.f\n", pt2);
  aff_secante(x4, x3, x2, x1, x0, pt1, pt2, argv);
  printf("Number of iterations too high. Convergeance doesn't reached\n");
}

void		option_choice(char **argv)
{
  printf("Équation: ");
  aff_equation(argv);
  if (atoi(argv[1]) == 1)
    bissection_choice(argv);
  else if (atoi(argv[1]) == 2)
    newton_choice(argv);
  else if (atoi(argv[1]) == 3)
    secante_choice(argv);
}
