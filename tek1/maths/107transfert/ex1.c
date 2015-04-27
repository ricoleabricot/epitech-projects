/*
** ex1.c for 107transfert in /home/gicque_p/local/maths/107transfert
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar  6 15:52:49 2014 Pierrick Gicquelais
** Last update Sun Mar  9 12:09:26 2014 Pierrick Gicquelais
*/

#include	<sys/timeb.h>
#include	<time.h>
#include	"transfert.h"

void		algo_horner(int *tab, int pow_nb)
{
  int		i;
  int		res;
  double	step;

  i = 0;
  res = 0;
  step = 0;
  while (step <= 1000)
    {
      res = 0;
      for (i = 0 ; i <= pow_nb ; i++)
	res = step * res + tab[i];
      step += 0.001;
    }
  usleep(4000);
}

void		algo_naif(int *tab, int pow_nb)
{
  int		i;
  int		res;
  int		stock;
  double	step;

  i = 0;
  step = 0;
  while (step <= 1000)
    {
      res = 0;
      i = 0;
      stock = pow_nb;
      for (stock = pow_nb ; stock > 0 ; stock--)
	{
	  res += tab[i] * my_pow(step, stock);
	  i++;
	}
      step += 0.001;
    }
}

void		horner(int *tab, int pow)
{
  struct timeb	*t;
  int		time;

  time = 0;
  t = malloc(sizeof(struct timeb));
  printf("Méthode de Horner:\t");
  ftime(t);
  time = t->millitm;
  algo_horner(tab, pow);
  ftime(t);
  time = abs(time - t->millitm);
  printf("%d millisecondes\n", time);
}

void		naif(int *tab, int pow)
{
  struct timeb	*t;
  int		time;

  time = 0;
  t = malloc(sizeof(struct timeb));
  printf("Algorithme naïf:\t");
  ftime(t);
  time = t->millitm;
  algo_naif(tab, pow);
  ftime(t);
  time = abs(time - t->millitm);
  printf("%d millisecondes\n", time);
}

void		ex1(char *str)
{
  char		**tab;
  int		*tab_int;
  int		pow;

  if (str[0] == '\0')
    string_error(1);
  printf("\033[01;37m");
  printf("Evaluation du polynôme: ");
  pow = check_string(str);
  tab = my_str_to_wordtab(str);
  tab_int = my_tab_to_int(tab, pow + 1);
  aff_equation(tab_int, pow);
  printf(" en 1.000.000 de points\n");
  naif(tab_int, pow);
  horner(tab_int, pow + 1);
  my_free(tab);
  printf("\033[0m");
}
