/*
** math.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar  7 17:00:30 2014 Pierrick Gicquelais
** Last update Fri Mar  7 17:05:39 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

int		my_pow(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else
    return (nb * my_pow(nb, power - 1));
}
