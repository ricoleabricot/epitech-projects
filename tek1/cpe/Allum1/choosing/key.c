/*
** key.c for allum in /home/gicque_p/local/cpe/Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Feb  5 22:43:33 2014 Pierrick Gicquelais
** Last update Wed Feb 12 22:24:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../allum.h"

int		down_key(char *s1, char *s2, int i)
{
  int		mod;

  tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, my_putchar);
  tputs(tgetstr("ce", NULL), 1, my_putchar);
  my_putstr(s1);
  tputs(tgoto(tgetstr("cm", NULL), 0, i + 1), 1, my_putchar);
  my_putstr("--> ");
  tputs(tgetstr("md", NULL), 1, my_putchar);
  tputs(tgetstr("us", NULL), 1, my_putchar);
  my_putstr(s2);
  tputs(tgetstr("me", NULL), 1, my_putchar);
  mod = 2;
  return (mod);
}

int		up_key(char *s1, char *s2, int i)
{
  int		mod;

  tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, my_putchar);
  tputs(tgetstr("ce", NULL), 1, my_putchar);
  my_putstr(s1);
  tputs(tgoto(tgetstr("cm", NULL), 0, i - 1), 1, my_putchar);
  my_putstr("--> ");
  tputs(tgetstr("md", NULL), 1, my_putchar);
  tputs(tgetstr("us", NULL), 1, my_putchar);
  my_putstr(s2);
  tputs(tgetstr("me", NULL), 1, my_putchar);
  mod = 1;
  return (mod);
}
