/*
** aff.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Dec 27 00:18:50 2013 Pierrick Gicquelais
** Last update Fri Jan  3 15:47:00 2014 Pierrick Gicquelais
*/

#include "section.h"

void	maff_final(double x1, double x2, char **argv)
{
  double	xp1;
  double	yp1;
  double	zp1;
  double	xp2;
  double	yp2;
  double	zp2;

  xp1 = atof(argv[2]) + x1 * atof(argv[5]);
  yp1 = atof(argv[3]) + x1 * atof(argv[6]);
  zp1 = atof(argv[4]) + x1 * atof(argv[7]);
  xp2 = atof(argv[2]) + x2 * atof(argv[5]);
  yp2 = atof(argv[3]) + x2 * atof(argv[6]);
  zp2 = atof(argv[4]) + x2 * atof(argv[7]);

  printf("Point 1 : (%.3f, %.3f, %.3f)\n", xp1, yp1, zp1);
  printf("Point 2 : (%.3f, %.3f, %.3f)\n", xp2, yp2, zp2);
}

void	maff_result(double a, double b, double delta, char **argv)
{
  double	x1;
  double	x2;

  if (delta < 0)
    printf("Nombre de points d'intersections : 0\n");
  if (delta == 0)
    {
      printf("Nombre de points d'intersections : 1\n");
      printf("Point d'intersection : (%.3f, %.3f, %.3f)\n", (-b / 2 * a), (-b /\
									   2 * a), atof(argv[4]));
    }
  if (delta > 0)
    {
      printf("Nombre de points d'intersections : 2\n");
      x1 = (-b - sqrt(delta)) / (2 * a);
      x2 = (-b + sqrt(delta)) / (2 * a);
      maff_final(x1, x2, argv);
    }
}
