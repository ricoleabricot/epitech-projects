/*
** my_error_2.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Apr  9 13:53:01 2014 Nicolas Ribeiro Teixeira
** Last update Thu Apr 10 16:04:27 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"lib.h"

void		label_undefined(int line_nbr, char *label)
{
  my_putstr("Label ");
  my_putstr(label);
  my_putstr(" undefined line : ");
  my_put_nbr(line_nbr);
  my_putchar('\n');
}

void		my_warnings(int exit_nbr, int line_nbr)
{
  if (exit_nbr == 1)
    {
      my_putstr("[WARNING] : Direct too big line : ");
      my_put_nbr(line_nbr);
      my_putchar('\n');
    }
  else if (exit_nbr == 4)
    {
      my_putstr("[WARNING] : Indirection too far line : ");
      my_put_nbr(line_nbr);
      my_putchar('\n');
    }
}

void		no_such_register(int line_nbr)
{
  my_putstr("No Such Register line : ");
  my_put_nbr(line_nbr);
  my_putchar('\n');
  exit(3);
}
