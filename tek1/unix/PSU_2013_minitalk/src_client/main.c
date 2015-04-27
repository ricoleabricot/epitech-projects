/*
** signal2.c for tp in /home/gicque_p/local/unix
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 10 10:39:21 2014 Pierrick Gicquelais
** Last update Fri Mar 14 16:57:40 2014 Pierrick Gicquelais
*/

#include	"minitalk.h"

int		main(int argc, char **argv)
{
  if (argc != 3)
    my_error("Error 1: You must enter two arguments to launch the client", 1);
  if (my_getnbr(argv[1]) <= 0)
    my_error("Error 2: You must enter a strict positive PID (arg 1)", 2);
  my_time(my_getnbr(argv[1]));
  my_send(my_getnbr(argv[1]), argv[2]);
  return (0);
}
