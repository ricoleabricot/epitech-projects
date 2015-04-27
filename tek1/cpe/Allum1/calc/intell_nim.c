/*
** intell_nim.c for allum1 in /home/gicque_p/local/cpe/Allum1/calc
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Wed Feb 12 19:08:39 2014 Pierrick Gicquelais
** Last update Fri Feb 14 12:03:11 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	"../allum.h"

int		my_boucle(t_var *f, int *line)
{
  int		i;
  int		max;
  int		xor;

  i = 0;
  max = *line;
  while (++i < max)
    {
      if (*line - i >= 0)
	{
	  *line -= i;
	  xor = f->line[0] ^ f->line[1] ^ f->line[2] ^ f->line[3];
	  if (xor == 1)
	    return (i);
	  *line += i;
	}
    }
  return (42);
}

int		my_xor(t_var *f)
{
  int		xor;

  if ((xor = my_boucle(f, &f->line[0])) != 42)
    return (xor);
  else if ((xor = my_boucle(f, &f->line[1])) != 42)
    return (xor);
  else if ((xor = my_boucle(f, &f->line[2])) != 42)
    return (xor);
  else if ((xor = my_boucle(f, &f->line[3])) != 42)
    return (xor);

  if (f->line[0] > 0)
    f->line[0] -= 1;
  else if (f->line[1] > 0)
    f->line[1] -= 1;
  else if (f->line[2] > 0)
    f->line[2] -= 1;
  else if (f->line[3] > 0)
    f->line[3] -= 1;
  else
    return (42);
  return (1);
}

int		marienbad(t_var *f, int total)
{
  int		xor;

  my_putstr("AI is playing ...\n");
  sleep(1);
  xor = my_xor(f);
  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  my_putstr("The AI withdraws ");
  my_putnbr(xor);
  my_putstr(" matche(s)\n");
  ending_intell(f, total);
  return (total);
}

int		easy_marienbad(t_var *f, int total)
{
  my_putstr("AI is playing ...\n");
  sleep(1);
  if (f->line[0] > 0)
    f->line[0]--;
  else if (f->line[1] > 0)
    f->line[1]--;
  else if (f->line[2] > 0)
    f->line[2]--;
  else if (f->line[3] > 0)
    f->line[3]--;
  total = f->line[0] + f->line[1] + f->line[2] + f->line[3];
  my_putstr("The AI withdraws 1 matche\n");
  ending_intell(f, total);
  return (total);
}
