/*
** my_getnbr.c for my_getnbr in /home/boisso_c/rendu/Piscine-C-lib/my/source
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Tue Oct  8 13:19:39 2013 Christian Boisson
** Last update Sat Apr 12 15:40:52 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"lib.h"

void		my_errnbr(char *str, int line_nbr)
{
  char		n;
  int		a;

  a = 0;
  n = 0;
  while (str[0] == '+' || str[0] == '-')
    {
      str++;
      a++;
    }
  if (a != 0)
    str--;
  if (str[0] == '-')
    n = 1;
  check_errnbr(str, n, line_nbr);
}

void		check_errnbr(char *str, char n, int line_nbr)
{
  int		i;
  int		t;
  long		nbr;

  t = 0;
  i = my_strlen(str);
  nbr = 0;
  if (i > 11 || (i > 10 && n == 0))
    my_error(1, NULL, line_nbr, NULL);
  while (47 < str[t] && str[t] < 58 && t <= i)
    t++;
  while (t > 0)
    {
      nbr = nbr * 10 + str[0] - 48;
      str++;
      t--;
    }
  if (nbr < -2147483648 || nbr > 2147483647)
    my_error(1, NULL, line_nbr, NULL);
}
