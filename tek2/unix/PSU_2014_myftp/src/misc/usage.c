/*
** misc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 10:54:21 2015 Pierrick Gicquelais
** Last update Tue Mar 24 23:49:10 2015 Pierrick Gicquelais
*/

#include	"usage.h"

void		usage(char **argv)
{
  if (strcmp(argv[0], "./server") == 0)
    fprintf(stdout, "%s: port_value\n", argv[0]);
  else if (strcmp(argv[0], "./client") == 0)
    fprintf(stdout, "%s: ip_value port_value\n", argv[0]);
  exit(EXIT_FAILURE);
}
