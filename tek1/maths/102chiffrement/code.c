/*
** code.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Nov 24 18:04:51 2013 Pierrick Gicquelais
** Last update Sat Nov 30 14:28:33 2013 Pierrick Gicquelais
*/

#include "main.h"

void	my_encode(char **argv)
{
  int	*tab;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  tab = malloc(my_strlen(argv[1]) * sizeof(int));
  while (argv[1][i])
    {
      if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
	tab[i] = argv[1][i] - 96;
      else if (argv[1][i] == ' ')
	tab[i] = 0;
      i++;
      nb++;
    }
  matrice_prod(tab, nb, argv);
}

int	pos_base(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] && base[i] != c)
    i++;
  if (base[i] == 0)
    return (-1);
  return (i);
}

void	my_decode(char **argv)
{
  int	i;
  int	j;
  int	a;
  int	*tab;
  int	i_save;

  i = 0;
  i_save = 0;
  j = 0;
  tab = malloc(my_strlen(argv[1]) * sizeof(int));
  printf("\033[01;37mDéchiffrement du message '%s' à l'aide de la clé (%s %s %s %s) dans la base '%s'\n", \
	 argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);  
  while (argv[1][i] != '\0')
    {
      a = 0;
      tab[j] = 0;
      i_save = i;
      while (argv[1][i] && argv[1][i] != ' ')
	{
	  a++;
	  i++;
	}
      i = i_save;
      a--;
      while (argv[1][i] && argv[1][i] != ' ')
        {
	  tab[j] = tab[j] + pos_base(argv[1][i], argv[6]) * pow(my_strlen(argv[6]), a);
          a--;
          i++;
        }
      while (argv[1][i] == ' ')
        i++;
      j++;
    }
  my_decode_next(argv, tab, j);
}

void	my_decode_next(char **argv, int *tab, int j)
{
  int	*tab2;
  int	*tab3;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tab3 = malloc(j * sizeof(char));
  tab2 = inverse_matrice(argv);
  my_putstr("=> ");
  while (i < j)
    {
      tab3[k] = (tab[i] * tab2[0]) + (tab[i + 1] * tab2[1]);
      if (tab3[k] == 0)
	my_putchar(' ');
      else
	my_putchar(tab3[k] + 96);
      tab3[k + 1] = (tab[i] * tab2[2]) + (tab[i + 1] * tab2[3]);
      if (tab3[k + 1] == 0)
	my_putchar(' ');
      else
	my_putchar(tab3[k + 1] + 96);
      k = k + 2;
      i = i + 2;
    }
}
