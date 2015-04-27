/*
** main.c for bsq in /home/gicque_p/local/cpe/CPE_2013_BSQ
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Dec  8 14:14:25 2013 Pierrick Gicquelais
** Last update Sun Dec  8 18:11:03 2013 Pierrick Gicquelais
*/

#include "bsq.h"

int	main(int argc, char **argv)
{
  int	fd;
  char	*s;

  if (argc != 2)
    my_error("Must be only one argument");
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    my_error("Impossible to open the file");
  while ((s = get_next_line(fd)) != NULL)
    {
      my_putstr(s);
      my_putchar('\n');
      free(s);
    }
  close(fd);
  return (0);
}
