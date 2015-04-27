/*
** calc.c for 103architecte in /home/gicque_p/local/maths/103architecte
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec  9 10:05:14 2013 Pierrick Gicquelais
** Last update Thu Dec 12 18:33:11 2013 Pierrick Gicquelais
*/

#include "architecte.h"

double	*my_translation(double *resultat, double *matrice, char **argv, int i)
{
  double	Tx;
  double	Ty;

  Tx = atof(argv[i + 1]);
  Ty = atof(argv[i + 2]);
  matrice[2] = matrice[2] + Tx;
  matrice[5] = matrice[5] + Ty;
  printf("\033[01;37mTranslation de vecteur (%.0f, %.0f)\n", Tx, Ty);
  resultat[0] = resultat[0] + Tx;
  resultat[1] = resultat[1] + Ty;
  return (resultat);
}

double	*my_homothetie(double *resultat, double *matrice, char **argv, int i)
{
  double	Hx;
  double	Hy;

  Hx = atof(argv[i + 1]);
  Hy = atof(argv[i + 2]);
  matrice[0] = matrice[0] * Hx;
  matrice[1] = matrice[1] * Hx;
  matrice[2] = matrice[2] * Hx;
  matrice[3] = matrice[3] * Hy;
  matrice[4] = matrice[4] * Hy;
  matrice[5] = matrice[5] * Hy;
  printf("\033[01;37mHomothétie de rapports %.0f et %.0f\n", Hx, Hy);
  resultat[0] = resultat[0] * Hx;
  resultat[1] = resultat[1] * Hy;
  return (resultat);
}

double	*my_rotation(double *resultat, double *matrice, char **argv, int i)
{
  double	matrice_rotation[9];
  double	a;
  double	Rx;
  double	Ry;
  double	stock;

  a = atof(argv[i + 1]);
  a = (a * M_PI) / 180;
  Rx = cos(a);
  Ry = sin(a);
  fill_mat_rot(&matrice_rotation[0], Rx, Ry);
  mult_mat(&matrice[0], &matrice_rotation[0]);
  printf("\033[01;37mRotation par rapport à un angle de %s degré(s)\n", argv[i + 1]);
  stock = resultat[0];
  resultat[0] = stock * matrice_rotation[0] + resultat[1] * matrice_rotation[1];
  resultat[1] = stock * matrice_rotation[3] + resultat[1] * matrice_rotation[4];
  return (resultat);
}

double	*my_symetrie(double *resultat, double *matrice, char **argv, int i)
{
  double	matrice_symetrie[9];
  double	a;
  double	Sx;
  double	Sy;
  double	stock;

  a = atof(argv[i + 1]);
  a = (a * M_PI) / 180;
  Sx = cos(2 * a);
  Sy = sin(2 * a);
  fill_mat_sym(&matrice_symetrie[0], Sx, Sy);
  mult_mat(&matrice[0], &matrice_symetrie[0]);
  printf("\033[01;37mSymétrie par rapport à un axe de %s degré(s)\n", argv[i + 1]);
  stock = resultat[0];
  resultat[0] = stock * matrice_symetrie[0] + resultat[1] * matrice_symetrie[1];
  resultat[1] = stock * matrice_symetrie[3] + resultat[1] * matrice_symetrie[4];
  return (resultat);
}
