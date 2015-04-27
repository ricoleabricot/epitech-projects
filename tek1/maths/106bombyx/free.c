/*
** free.c for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 12:56:11 2014 Pierrick Gicquelais
** Last update Mon Feb 10 12:59:27 2014 Pierrick Gicquelais
*/

#include	"bombyx.h"

void		my_free(t_bomb *bomb)
{
  free(bomb->ptr);
  free(bomb->nb);
  my_error("Echap Key. End of Programm !", 42);
}
