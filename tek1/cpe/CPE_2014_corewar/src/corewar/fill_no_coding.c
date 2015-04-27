/*
** fill_no_coding.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/Elfen
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Fri Apr 11 13:36:18 2014 Christian Boisson
** Last update Sat Apr 12 12:20:27 2014 Christian Boisson
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"
#include	"maccro.h"
#include	"funct.h"
#include	"struct.h"

int		fill_no_coding(unsigned char arena[], int op, t_champ *tmp)
{
  fill_instru(0, 0, tmp, 0);
  if (op == 1)
    fill_param(tmp, arena, 0, 4);
  else if (op == 9)
    fill_param(tmp, arena, 0, 2);
  else if (op == 12)
    fill_param(tmp, arena, 0, 2);
  else if (op == 15)
    fill_param(tmp, arena, 0, 2);
  fill_instru(op, arena[tmp->pc + 1], tmp, 1);
  return (0);
}

int		try_p_ind(unsigned char arena[], t_champ *tmp, int op, int code)
{
  if (op == 10)
    {
      if (((code >> 6) & 0x3) == 1)
	fill_param(tmp, arena, 0, 1);
      else
	fill_param(tmp, arena, 0, 2);
      if (((code >> 4) & 0x3) == 1)
	fill_param(tmp, arena, 1, 1);
      else
	fill_param(tmp, arena, 1, 2);
      fill_param(tmp, arena, 2, 1);
    }
  else if (op == 11)
    {
      fill_param(tmp, arena, 0, 1);
      if (((code >> 4) & 0x3) == 1)
	fill_param(tmp, arena, 1, 1);
      else
	fill_param(tmp, arena, 1, 2);
      if (((code >> 2) & 0x3) == 1)
	fill_param(tmp, arena, 2, 1);
      else
	fill_param(tmp, arena, 2, 2);
    }
  return (0);
}

