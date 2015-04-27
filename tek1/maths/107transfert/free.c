/*
** free.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar  7 12:48:41 2014 Pierrick Gicquelais
** Last update Fri Mar  7 12:49:12 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

void		my_free(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
