/*
** exec.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/Elfen
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Wed Apr  9 10:45:50 2014 Christian Boisson
** Last update Sat Apr 12 14:35:58 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

void		exec_proc(t_vm *vm, t_champ *champ, \
			  int (*function_tab[17])(t_vm *, t_champ *))
{
  int		op;
  int		ret;

  op = champ->instru->opcode;
  ret = (function_tab[op])(vm, champ);
  if (op == 2 || (4 <= op && op <= 8) || op == 10 ||	\
      op == 13 || op == 14)
    {
      if (ret == 0)
	champ->carry = 1;
      else
	champ->carry = 0;
    }
  champ->pc += champ->instru->size;
  champ->instru->exec_cycle = -1;
  champ->instru->size = 0;
}
