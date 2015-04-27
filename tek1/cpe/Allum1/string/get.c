/*
** my_getnbr.c for my_getnbr in /home/gicque_p/piscine/piscine4
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Oct  4 16:32:12 2013 Pierrick Gicquelais
** Last update Fri Feb 14 10:08:14 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

void		my_getnick(t_var *var)
{
  my_putstr("Enter the first player nickname: ");
  while ((var->j1 = get_next_line(0)) == NULL);
  my_putstr("Enter the second player nickname: ");
  while ((var->j2 = get_next_line(0)) == NULL);
  check_name(var->j1, var->j2);
}

int		get_info(t_var *var, char *str, int i)
{
  char          *s;
  int           choice;

  if (i % 2 == 0)
    {
      my_putstr(var->j1);
      my_putstr(str);
    }
  else
    {
      my_putstr(var->j2);
      my_putstr(str);
    }
  while ((s = get_next_line(0)) == NULL);
  choice = my_getnbr(s);
  return (choice);
}

int		my_getnbr(char *str)
{
  int           i;
  int           n;

  i = 0;
  n = 0;
  if (str[0] == '-' && str[1] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      n = n + str[i] - 48;
      n = n * 10;
      i++;
    }
  n /= 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}
