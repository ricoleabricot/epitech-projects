/*
** my_error.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Thu Mar 27 11:11:00 2014 Nicolas Ribeiro Teixeira
** Last update Thu Apr 10 16:03:20 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"asm.h"

void		my_zero(int exit_nbr, int line_nbr)
{
  my_putstr("Syntax error line : ");
  my_put_nbr(line_nbr);
  my_putchar('\n');
  exit(exit_nbr);
}

void		my_six(int exit_nbr, char *error, char *label)
{
  my_putstr(error);
  my_putstr(" line : \'");
  my_putstr(label);
  my_putstr("\'\n");
  exit(exit_nbr);
}

void		my_five(int exit_nbr, char *error)
{
  my_putstr(error);
  my_putchar('\n');
  exit(exit_nbr);
}

void		my_error(int exit_nbr, char *error, int line_nbr, char *label)
{
  if (exit_nbr == 0)
    my_zero(exit_nbr, line_nbr);
  else if (exit_nbr == 2)
    {
      label_undefined(line_nbr, label);
      exit(exit_nbr);
    }
  else if (exit_nbr == 3)
    {
      no_such_register(line_nbr);
      exit(exit_nbr);
    }
  else if (exit_nbr == 4 || exit_nbr == 1)
    my_warnings(exit_nbr, line_nbr);
  else if (exit_nbr == 5)
    my_five(exit_nbr, error);
  else if (exit_nbr == 6)
    my_six(exit_nbr, error, label);
}
