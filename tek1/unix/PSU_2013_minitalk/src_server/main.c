/*
** signal.c for tp in /home/gicque_p/local/unix
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 10 09:55:52 2014 Pierrick Gicquelais
** Last update Tue Mar 11 14:01:40 2014 Pierrick Gicquelais
*/

#include	<signal.h>
#include	<unistd.h>
#include	"minitalk.h"

int		main()
{
  my_putstr("PID du serveur: ");
  my_putnbr(getpid());
  my_putchar('\n');
  usleep(1000);
  if ((signal(SIGUSR1, sig_handler)) == SIG_ERR)
    my_error("Error 1: Cannot set signal for SIGUSR1", 1);
  if ((signal(SIGUSR2, sig_handler)) == SIG_ERR)
    my_error("Error 2: Cannot set signal for SIGUSR2", 2);
  while (42);
  return (0);
}
