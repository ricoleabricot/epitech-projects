/*
** reveice.c for minitalk in /home/gicque_p/local/unix/PSU_2013_minitalk/src_server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 11 13:57:14 2014 Pierrick Gicquelais
** Last update Wed Mar 19 20:09:25 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"minitalk.h"

void		write_bit(int bit)
{
  static char	c;
  static int	i;

  c += bit << i;
  i++;
  if (i > 7)
    {
      if (c == '\n')
	my_putchar('\n');
      else
	my_putchar(c);
      c = 0;
      i = 0;
    }
}

void		sig_handler(int sign)
{
  if (sign == SIGUSR1)
    write_bit(1);
  if (sign == SIGUSR2)
    write_bit(0);
}
