/*
** usage.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:11 2015 Pierrick Gicquelais
** Last update Wed Apr  8 16:26:08 2015 Pierrick Gicquelais
*/

#include	"usage.h"

void		usage(char **argv)
{
  if (strcmp(argv[0], "./server") == 0)
    fprintf(stdout, "%s: port_value\n", argv[0]);
  else if (strcmp(argv[0], "./client") == 0)
    fprintf(stdout, "%s: (ip_value port_value)\n", argv[0]);
  exit(EXIT_FAILURE);
}
