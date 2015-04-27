/*
** write_arena.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Thu Apr 10 16:23:25 2014 Christian Boisson
** Last update Sat Apr 12 15:54:42 2014 Nicolas Ribeiro Teixeira
*/

#include	"maccro.h"
#include	"struct.h"
#include	"funct.h"

void		write_arena(int pos, unsigned char arena[], int nb)
{
  int		oct_a;
  int		oct_b;
  int		oct_c;
  int		oct_d;

  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0xFF;
  oct_c = (nb >> 16) & 0xFF;
  oct_d = (nb >> 24) & 0xFF;
  arena[pos % MEM_SIZE] = oct_d;
  arena[(pos + 1) % MEM_SIZE] = oct_c;
  arena[(pos + 2) % MEM_SIZE] = oct_b;
  arena[(pos + 3) % MEM_SIZE] = oct_a;
}
