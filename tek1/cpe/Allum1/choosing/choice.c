/*
** choice.c for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb  4 23:07:12 2014 Pierrick Gicquelais
** Last update Fri Feb 14 10:34:47 2014 Pierrick Gicquelais
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"../allum.h"

int			choose_all(t_var *var, int option, int line1, int line2)
{
  char			buf[64];
  int			mod;
  int			size;

  mod = 1;
  check_option(var, option);
  while ((size = read(0, buf, 3)) != 0)
    {
      if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
	mod = down_key(var->s1, var->s2, line1);
      else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
	mod = up_key(var->s2, var->s1, line2);
      else if (buf[0] == 10 && size == 1)
	{
	  if (mod == 1)
	    var->choice[option] = 1;
	  else if (mod == 2)
	    var->choice[option] = 2;
	  return (0);
	}
    }
  return (0);
}

void			my_choice()
{
  struct termios	t;
  t_var			*var;

  if ((var = malloc(sizeof(t_var))) == NULL)
    my_error("Error with a memory allocation");
  if (tcgetattr(0, &t) == -1)
    my_error("Error with syscall tcgetattr");
  raw_attr(&t);
  tputs(tgetstr("vi", NULL), 1, my_putchar);
  display_mod(var);
  display_pvp(var);
  if (var->choice[1] == 1)
    display_difficulty(var);
  canon_attr(&t);
  tputs(tgetstr("ve", NULL), 1, my_putchar);
  launch_game(var);
}
