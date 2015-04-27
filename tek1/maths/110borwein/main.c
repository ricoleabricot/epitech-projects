/*
** main.c for 110borwein in /home/gicque_p/rendu/110borwein
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Apr  7 08:49:38 2014 Pierrick Gicquelais
** Last update Fri Apr 18 11:45:43 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<math.h>

static int	*fill_tab(int [], char **);
static int	rectangle(int []);
static int	trapeze(int []);
static int	simpson(int []);
static int	gauss(int []);
static double	fx(int, double);

int		main(int argc, char **argv)
{
  int		tab[5];

  if (argc < 2) {
    printf("\033[01;06;33mUSAGE: n (positive) [start] [end] ");
    printf("[subdivision (strict positive)] [precision (positive)]\n");
    printf("If an error occur, start will be a 0, end at 5000, ");
    printf("subdivision at 10000 and precision at 10\n\033[0m");
    exit(EXIT_FAILURE); }
  else if ((tab[0] = atoi(argv[1])) < 0) {
    printf("You must enter a positive value for 'n' (arg 1)\n"); exit(EXIT_FAILURE); }
  fill_tab(tab, argv);
  rectangle(tab);
  trapeze(tab);
  simpson(tab);
  gauss(tab);
  return (0);
}

static int	*fill_tab(int tab[4], char **argv)
{
  int		i = 2;
  if (argv[i])
    tab[1] = atoi(argv[i++]);
  else
    tab[1] = 0;
  if (argv[i])
    tab[2] = atoi(argv[i++]);
  else
    tab[2] = 5000;
  if (argv[i] && atoi(argv[i]) > 0)
    tab[3] = atoi(argv[i++]);
  else
    tab[3] = 10000;
  if (argv[i] && atoi(argv[i]) >= 0)
    tab[4] = atoi(argv[i++]);
  else
    tab[4] = 10;
  return (tab);
}

static double	fx(int n, double x)
{
  double	somme = 1;
  int		k = -1;

  while (++k <= n)
    if (x != 0)
      somme *= (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
  return (somme);
}

static int	rectangle(int tab[])
{
  double	a = tab[1];
  double	b = tab[2];
  double	h = (b - a) / tab[3];
  double	somme = 0;
  int		i = a - 1;

  if (b > 0)
    while (++i < tab[3])
      somme += fx(tab[0], a + i * h);
  else
    while (--i > tab[3])
      somme += fx(tab[0], a + i * h);

  somme *= (b - a) / tab[3];

  printf("\033[01;04;37mMéthode des rectangles:\n\033[0m");
  printf("I%d: %.*f\n", tab[0], tab[4], somme);
  printf("Diff: %.*f\n\n", tab[4], somme - M_PI / 2);
  return (0);
}

static int	trapeze(int tab[])
{
  double	a = tab[1];
  double	b = tab[2];
  double	h = (b - a) / tab[3];
  double	somme = 0;
  int		i = a;

  if (b > 0)
    while (++i < tab[3])
      somme += fx(tab[0], a + i * h);
  else
    while (--i > tab[3])
      somme += fx(tab[0], a + i * h);

  somme = ((somme * 2) + fx(tab[0], a) + fx(tab[0], b)) * ((b - a) / (2 * tab[3]));

  printf("\033[01;04;37mMéthode des trapèzes:\n\033[0m");
  printf("I%d: %.*f\n", tab[0], tab[4], somme);
  printf("Diff: %.*f\n\n", tab[4], (somme - M_PI / 2));
  return (0);
}

static int	simpson(int tab[])
{
  double	a = tab[1];
  double	b = tab[2];
  double	h = (b - a) / tab[3];
  double	somme1 = 0;
  double	somme2 = 0;
  double	somme3 = 0;
  int		i = a;

  if (b > 0)
    while (++i < tab[3])
      somme1 += fx(tab[0], a + i * h);
  else
    while (--i > tab[3])
      somme1 += fx(tab[0], a + i * h);

  i = -1;
  if (b > 0)
    while (++i < tab[3])
      somme2 += fx(tab[0], (a + i * h) + (h / 2));
  else
    while (--i > tab[3])
      somme2 += fx(tab[0], (a + i * h) + (h / 2));

  somme3 = ((somme1 * 2) + (somme2 * 4) + fx(tab[0], a) + fx(tab[0], b)) * ((b - a) / (6 * tab[3]));

  printf("\033[01;04;37mMéthode de Simpson:\n\033[0m");
  printf("I%d: %.*f\n", tab[0], tab[4], somme3);
  printf("Diff: %.*f\n\n", tab[4], (somme3 - M_PI / 2));
  return (0);
}

static int	gauss(int tab[])
{
  double	a = tab[1];
  double	b = tab[2];
  double	h = (b - a) / tab[3];
  double	somme = 0;
  int		i = a;

  if (b > 0)
    while (++i < tab[3])
      somme += fx(tab[0], (((b - a) / 2) * i + (a + b) / 2));
  else
    while (--i > tab[3])
      somme += fx(tab[0], (((b - a) / 2) * i + (a + b) / 2));

  somme *= h * (b - a) / 2;

  printf("\033[01;04;37mMéthode de Gauss:\n\033[0m");
  printf("I%d: %.*f\n", tab[0], tab[4], somme);
  printf("Diff: %.*f\n", tab[4], somme - M_PI / 2);
  return (0);
}
