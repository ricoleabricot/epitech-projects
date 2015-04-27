/*
** get_octet.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Thu Apr 10 15:10:44 2014 Christian Boisson
** Last update Fri Apr 11 13:48:06 2014 Nicolas Ribeiro Teixeira
*/

#include	"maccro.h"
#include	"struct.h"
#include	"funct.h"

int		get_int(int pos, unsigned char arena[], int nbr)
{
  int		i;
  int		nb;
  int		mult;

  i = 0;
  nb = 0;
  mult = 1;
  while (i < nbr)
    {
      nb += arena[(pos + i) % MEM_SIZE] * mult;
      mult = mult * 256;
      i++;
    }
  return (nb);
}
