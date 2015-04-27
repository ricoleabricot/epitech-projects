/*
** option.c for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 17 21:51:40 2013 Pierrick Gicquelais
** Last update Sat Jan  4 21:45:35 2014 Pierrick Gicquelais
*/

#include "section.h"

void	check_option(char **argv)
{
  if ((atof(argv[1]) == 1 || atof(argv[1]) == 2) && atof(argv[8]) == 0)
    my_error("Argument 8 is invalid. You must enter a strict positive value");
  if (atof(argv[1]) == 1)
    my_sphere(argv);
  else if (atof(argv[1]) == 2)
    my_cylinder(argv);
  else if (atof(argv[1]) == 3)
    my_cone(argv);
  else
    my_error("Wrong option. You must enter as first argument '1' for a sphere, '2' for a cylinder or '3' for a cone\nBONUS: You can also enter '1.1' for a sphere with a non-null center\nBONUS: You can also enter '2.1' for a cylinder with a non-null center");
}

void	my_sphere(char **argv)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  printf("Sphère de rayon %s unité(s)\n", argv[8]);
  printf("Droite passant par le point (%s, %s, %s), de vecteur directeur (%s, %s, %s)\n", \
	 argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);

  a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) + pow(atof(argv[7]), 2);
  b = (2 * atof(argv[2]) * atof(argv[5])) + (2 * atof(argv[3]) * atof(argv[6])) + (2 * atof(argv[4]) * atof(argv[7]));
  c = (pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) + pow(atof(argv[4]), 2)) - pow(atof(argv[8]), 2);
  delta = b * b - 4 * a * c;

  maff_result(a, b, delta, argv);
}

void	my_cylinder(char **argv)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  printf("Cylindre de rayon %s unité(s)\n", argv[8]);
  printf("Droite passant par le point (%s, %s, %s), de vecteur directeur (%s, %s, %s)\n", \
	 argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);

  a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2);
  b = (2 * atof(argv[2]) * atof(argv[5])) + (2 * atof(argv[3]) * atof(argv[6]));
  c = (pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2)) - pow(atof(argv[8]), 2);
  delta = b * b - 4 * a * c;

  maff_result(a, b, delta, argv);
}

void	my_cone(char **argv)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	angle;

  angle = (atof(argv[8]) * M_PI) / 180;
  printf("Cône d'angle %s degré(s)\n", argv[8]);
  printf("Droite passant par le point (%s, %s, %s), de vecteur directeur (%s, %s, %s)\n", \
	 argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);

  a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) - (pow(atof(argv[7]), 2) / pow(tan(angle), 2));
  b = (2 * atof(argv[2]) * atof(argv[5])) + (2 * atof(argv[3]) * atof(argv[6])) - (2 * atof(argv[4]) * atof(argv[7]) / pow(tan(angle), 2));
  c = pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) - pow(atof(argv[4]), 2) / pow(tan(angle), 2);
  delta = b * b - 4 * a * c;

  maff_result(a, b, delta, argv);
}
