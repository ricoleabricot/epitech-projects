/*
** str.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Apr 17 10:58:41 2014 Pierrick Gicquelais
** Last update Thu Apr 17 11:33:34 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_fputchar(int fd, char c)
{
  return (write(fd, &c, 1));
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void		my_fputstr(int fd, char *s)
{
  while (*s)
    my_fputchar(fd, *s++);
}

void		my_error(char *s, int error)
{
  my_fputstr(2, s);
  my_fputchar(2, '\n');
  exit(error);
}
