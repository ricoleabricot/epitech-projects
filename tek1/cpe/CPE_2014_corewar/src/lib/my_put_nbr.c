/*
** my_put_nbr.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/lib
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Tue Mar 18 10:44:48 2014 Nicolas Ribeiro Teixeira
** Last update Wed Mar 26 09:11:24 2014 Nicolas Ribeiro Teixeira
*/

#include	"lib.h"

void		my_put_nbr(int a)
{
  int		b;

  b = 0;
  if (a < 0)
    {
      my_putchar('-');
      a = a * -1;
    }
  if (a < 10)
    my_putchar(a + 48);
  else
    {
      my_put_nbr(a / 10);
      b = a % 10;
      my_putchar(b + 48);
    }
}
