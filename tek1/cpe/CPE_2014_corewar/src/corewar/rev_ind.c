/*
** rev_ind.c for coreware in /home/boisso_c/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Thu Apr 10 15:05:33 2014 Christian Boisson
** Last update Thu Apr 10 17:23:16 2014 Nicolas Ribeiro Teixeira
*/

int		rev_ind(int nb)
{
  int		oct_a;
  int		oct_b;

  oct_a = nb & 0xFF;
  oct_b = (nb >> 8) & 0xFF;
  return (oct_a * 256 + oct_b);
}
