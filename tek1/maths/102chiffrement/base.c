/*
** base.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Nov 30 09:40:27 2013 Pierrick Gicquelais
** Last update Sat Nov 30 12:12:23 2013 Pierrick Gicquelais
*/

#include "main.h"

void    convert_base(int nb, char *base)
{
  if (nb > my_strlen(base))
    convert_base(nb / my_strlen(base), base);
  my_putchar(base[nb % my_strlen(base)]);
}

