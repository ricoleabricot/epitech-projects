/*
** my_putchar.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/lib
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Tue Mar 18 10:43:05 2014 Nicolas Ribeiro Teixeira
** Last update Tue Apr  8 15:14:17 2014 Nicolas Ribeiro Teixeira
*/

#include	<unistd.h>
#include	"lib.h"

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}
