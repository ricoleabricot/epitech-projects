/*
** aff.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 24 22:03:40 2014 Pierrick Gicquelais
** Last update Sat Mar  8 10:49:14 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

void		aff_suscomp(int *tab_int, int pow, int pow2, int i)
{
  int		j;

  j = 0;
  printf("\n\t\t");
  aff_equation(tab_int, pow);
  printf("\n");
  printf("\033[01;32mComposant %d: \033[01;37m", i / 2);
  printf("\t");
  if (pow > pow2)
    while (j++ < pow * 6)
      printf("=");
  else
    while (j++ < pow2 * 6)
      printf("=");
  printf("\n");
}

void		aff_subcomp(int *tab_int, int pow)
{
  printf("\t\t");
  aff_equation(tab_int, pow);
  printf("\n\n");
}

void            aff_equation(int *arg_tab, int pow)
{
  int           i;

  i = 0;
  while (arg_tab[i])
    {
      if (pow - 1 == 0)
	{
	  if (arg_tab[i] != 0)
	    printf("%d", arg_tab[i]);
	}
      else if (arg_tab[i] != 0)
        {
          if (pow == 1)
            {
              if (arg_tab[i + 1] > 0)
                printf("%dx + ", arg_tab[i]);
              else
                printf("%dx ", arg_tab[i]);
            }
          else
            {
              if (arg_tab[i + 1] > 0)
		printf("%dx^%d + ", arg_tab[i], pow - 1);
              else
                printf("%dx^%d ", arg_tab[i], pow - 1);
            }
        }
      i++;
      pow--;
    }
}
