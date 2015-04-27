/*
** my_getnbr.c for rpg in /home/gicque_p/rendu/epic_js_fantasy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun May 11 14:25:47 2014 Pierrick Gicquelais
** Last update Sun May 11 14:25:48 2014 Pierrick Gicquelais
*/

#include	"lib.h"

int		aff(char *str, char n)
{
  int		i;
  int		t;
  long		nbr;

  t = 0;
  i = my_strlen(str);
  nbr = 0;
  if (i > 11 || (i > 10 && n == 0))
    return (0);
  while (47 < str[t] && str[t] < 58 && t <= i)
    t++;
  while (t > 0)
    {
      nbr = nbr * 10 + str[0] - 48;
      str++;
      t--;
    }
  if (nbr < -2147483648 || nbr > 2147483647)
    return (0);
  return (nbr);
}

int		my_getnbr(char *str)
{
  char		n;
  int		a;
  long		nbr;

  nbr = 0;
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
    {
      n = 1;
      str++;
    }
  nbr = aff(str, n);
  if (n == 1)
    nbr = - nbr;
  return (nbr);
}
