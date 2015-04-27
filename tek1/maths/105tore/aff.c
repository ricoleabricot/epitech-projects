/*
** aff.c for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 09:55:52 2014 Pierrick Gicquelais
** Last update Sun Jan 19 20:03:57 2014 Pierrick Gicquelais
*/

#include	"tore.h"

void		aff_bissection(double x4, double x3, double x2, double x1, double x0, double pt1, double pt2, char **argv)
{
  int		i;
  double	xm;
  double	fxm;
  double	fx1;

  i = 0;
  while (++i < 250)
    {
      if (round(pt1 * pow(10, atoi(argv[7]))) == round(pt2 * pow(10, atoi(argv[7]))))
        {
          printf("f(x): %.1e\n", fxm);
          exit(EXIT_SUCCESS);
        }
      xm = (pt1 + pt2) / 2;
      if (i <= 20)
        printf("Itération %d\t-> x: %.*f\n", i, i, xm);
      else
        printf("Itération %d\t-> x: %.20f\n", i, xm);
      fxm = (x4 * pow(xm, 4)) + (x3 * pow(xm, 3)) + (x2 * pow(xm, 2)) + (x1 * xm) + x0;
      fx1 = ((x4 * pow(pt1, 4)) + (x3 * pow(pt1, 3)) + (x2 * pow(pt1, 2)) + (x1 * pt1) + x0);
      if (fx1 * fxm < 0)
        pt2 = xm;
      else
        pt1 = xm;
    }
}

void		aff_newton(double x4, double x3, double x2, double x1, double x0, double xn1, char **argv)
{
  int		i;
  double	xn2;
  double	fxn;
  double	fxn2;
  double	fpxn;

  i = 0;
  while (++i < 250)
    {
      fxn = (x4 * pow(xn1, 4)) + (x3 * pow(xn1, 3)) + (x2 * pow(xn1, 2)) + (x1 * xn1) + x0;
      fpxn = (4 * (x4 * pow(xn1, 3))) + (3 * (x3 * pow(xn1, 2))) + (2 * x2 * xn1) + x1;
      if (fpxn == 0)
	my_error("Division by zero. End of programm");
      xn2 = xn1 - (fxn / fpxn);
      if (round(xn1 * pow(10, atoi(argv[7]))) == round(xn2 * pow(10, atoi(argv[7]))))
        {
          printf("f(x): %.1e\n", fxn2);
          exit(EXIT_SUCCESS);
        }
      fxn2 = (x4 * pow(xn2, 4)) + (x3 * pow(xn2, 3)) + (x2 * pow(xn2, 2)) + (x1 * xn2) + x0;
      printf("Itération %d\t-> x: %.15f\n", i, xn2);
      xn1 = xn2;
    }
}

void		aff_secante(double x4, double x3, double x2, double x1, double x0, double pt1, double pt2, char **argv)
{
  int		i;
  double	fpt1;
  double	fpt2;
  double	xn;
  double	fxn;

  i = 0;
  while (++i < 250)
    {
      if (round(pt1 * pow(10, atoi(argv[7]))) == round(pt2 * pow(10, atoi(argv[7]))))
        {
          printf("f(x): %.1e\n", fxn);
          exit(EXIT_SUCCESS);
        }
      fpt1 = (x4 * pow(pt1, 4)) + (x3 * pow(pt1, 3)) + (x2 * pow(pt1, 2)) + (x1 * pt1) + x0;
      fpt2 = (x4 * pow(pt2, 4)) + (x3 * pow(pt2, 3)) + (x2 * pow(pt2, 2)) + (x1 * pt2) + x0;
      if ((fpt2 - fpt1) == 0)
	my_error("Division by zero. End of programm");
      xn = pt2 - ((fpt2) * (pt2 - pt1) / (fpt2 - fpt1));
      fxn = (x4 * pow(xn, 4)) + (x3 * pow(xn, 3)) + (x2 * pow(xn, 2)) + (x1 * xn) + x0;
      printf("Itération %d\t-> x: %.15f\n", i, xn);
      pt1 = pt2;
      pt2 = xn;
    }
}

void		aff_equation(char **argv)
{
  if (atoi(argv[6]) != 0)
    printf("%sx⁴", argv[6]);
  if (atoi(argv[5]) > 0)
    printf("+%sx³", argv[5]);
  else if (atoi(argv[5]) < 0)
    printf("%sx³", argv[5]);
  if (atoi(argv[4]) > 0)
    printf("+%sx²", argv[4]);
  else if (atoi(argv[4]) < 0)
    printf("%sx²", argv[4]);
  if (atoi(argv[3]) > 0)
    printf("+%sx", argv[3]);
  else if (atoi(argv[3]) < 0)
    printf("%sx", argv[3]);
  if (atoi(argv[2]) > 0)
    printf("+%s", argv[2]);
  else if (atoi(argv[2]) < 0)
    printf("%s", argv[2]);
  printf(" = 0\n");
}
