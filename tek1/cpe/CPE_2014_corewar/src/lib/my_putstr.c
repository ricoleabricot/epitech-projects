/*
** my_putstr.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/lib
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Tue Mar 18 10:43:25 2014 Nicolas Ribeiro Teixeira
** Last update Tue Mar 18 10:46:56 2014 Nicolas Ribeiro Teixeira
*/

#include	"lib.h"

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
