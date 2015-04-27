/*
** str.c for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 25 15:02:47 2014 Pierrick Gicquelais
** Last update Thu Mar  6 13:39:56 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void		my_putstr(char *s)
{
  while (*s)
    {
      my_putchar(*s);
      s++;
    }
}

void		my_error(char *s, int error)
{
  my_putstr(s);
  my_putchar('\n');
  exit(error);
}

char		*epur_str(char *src)
{
  char		*dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((dest = malloc((my_strlen(src) + 1) * sizeof(char))) == NULL)
    my_error("Error 87: Error with a memory allocation", 87);
  while (src[i] == ' ')
    i++;
  while (src[i])
    {
      if (src[i] != ' ' || src[i + 1] != ' ')
	dest[j++] = src[i];
      i++;
    }
  dest[j] = '\0';
  if (dest[j - 1] == ' ')
    dest[j - 1] = '\0';
  return (dest);
}
