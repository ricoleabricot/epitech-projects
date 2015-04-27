/*
** bonus.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jan  4 20:33:07 2014 Pierrick Gicquelais
** Last update Sat Jan  4 21:43:43 2014 Pierrick Gicquelais
*/

#include "section.h"

void	bonus_final(double x1, double x2, char **argv)
{
  double        xp1;
  double        yp1;
  double        zp1;
  double        xp2;
  double        yp2;
  double        zp2;

  xp1 = atof(argv[5]) + x1 * atof(argv[8]);
  yp1 = atof(argv[6]) + x1 * atof(argv[9]);
  zp1 = atof(argv[7]) + x1 * atof(argv[10]);
  xp2 = atof(argv[5]) + x2 * atof(argv[8]);
  yp2 = atof(argv[6]) + x2 * atof(argv[9]);
  zp2 = atof(argv[7]) + x2 * atof(argv[10]);

  printf("Point 1 : (%.3f, %.3f, %.3f)\n", xp1, yp1, zp1);
  printf("Point 2 : (%.3f, %.3f, %.3f)\n", xp2, yp2, zp2);

}

void	maff_bonus(double a, double b, double delta, char **argv)
{
  double        x1;
  double        x2;

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
      bonus_final(x1, x2, argv);
    }
}

void	bonus_sphere(char **argv)
{
  double        a;
  double        b;
  double        c;
  double        delta;

  printf("Sphère de rayon %s unité(s) et de centre de coordonnées (%s,%s,%s)\n", argv[11], argv[2], argv[3], argv[4]);
  printf("Droite passant par le point (%s, %s, %s), de vecteur directeur (%s, %s, %s)\n", \
	 argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);

  a = pow(atof(argv[8]) - atof(argv[2]), 2) + pow(atof(argv[9]) - atof(argv[3]), 2) + pow(atof(argv[10]) - atof(argv[4]), 2);
  b = (2 * atof(argv[5]) * atof(argv[8]) - atof(argv[2])) + (2 * atof(argv[6]) * atof(argv[9]) - atof(argv[3])) + (2 * atof(argv[7]) * atof(argv[10]) - atof(argv[4]));
  c = (pow(atof(argv[5]) - atof(argv[2]), 2) + pow(atof(argv[6]) - atof(argv[3]), 2) + pow(atof(argv[7]) - atof(argv[4]), 2)) - pow(atof(argv[8]), 2);
  delta = b * b - 4 * a * c;

  if (a == 0)
    {
      printf("Nombre de points d'intersections : 0\n");
      exit(EXIT_SUCCESS);
    }
  maff_bonus(a, b, delta, argv);
}

void	bonus_cylinder(char **argv)
{
  double        a;
  double        b;
  double        c;
  double        delta;

  printf("Cylindre de rayon %s unité(s) et de centre de coordonnées (%s,%s,%s)\n", argv[11], argv[2], argv[3], argv[4]);
  printf("Droite passant par le point (%s, %s, %s), de vecteur directeur (%s, %s, %s)\n", \
	 argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);

  a = pow(atof(argv[8]) - atof(argv[2]), 2) + pow(atof(argv[9]) - atof(argv[3]), 2);
  b = (2 * atof(argv[5]) * atof(argv[8]) - atof(argv[2])) + (2 * atof(argv[6]) * atof(argv[9]) - atof(argv[3]));
  c = (pow(atof(argv[5]) - atof(argv[2]), 2) + pow(atof(argv[6]) - atof(argv[3]), 2)) - pow(atof(argv[8]), 2);
  delta = b * b - 4 * a * c;

  if (a == 0)
    {
      printf("Nombre de points d'intersections : 0\n");
      exit(EXIT_SUCCESS);
    }
  maff_bonus(a, b, delta, argv);
}

void	my_bonus(int argc, char **argv)
{
  int	i;

  i = 0;
  if (argc < 12)
    my_bonus_few_error(argc);
  if (argc > 12)
    my_bonus_many_error(argc);
  while (++i < argc)
    if (my_str_isnum(argv[i]) == 0)
      my_number_error(i, argv);
  if (atof(argv[8]) == 0 && atof(argv[9]) == 0 && atof(argv[10]) == 0)
    my_vector_error();
  if (atof(argv[11]) <= 0)
    my_radius_error();
  my_putstr("\033[01;37m");
  if (atof(argv[1]) == 1.1)
    bonus_sphere(argv);
  if (atof(argv[1]) == 2.1)
    bonus_cylinder(argv);
  my_putstr("\033[0;37m");
  exit(EXIT_SUCCESS);
}
