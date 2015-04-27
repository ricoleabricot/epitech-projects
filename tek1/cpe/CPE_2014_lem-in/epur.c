/*
** epur.c for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 18 11:33:00 2014 Pierrick Gicquelais
** Last update Fri Apr 18 15:45:30 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"funct.h"

int		is_alpha(char c)
{
  if (c >= 33 && c <= 126)
    return (0);
  return (1);
}

char		*epur_str(char *s)
{
  char		*new_s;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new_s = malloc(strlen(s) * sizeof(char))) == NULL)
    my_error("Error with a memory allocation", 3);
  while (s[i])
    {
      if (s[i] != ' ' && s[i] != '\t')
	new_s[j++] = s[i];
      if (j != 0 && is_alpha(s[i + 1]) == 0 && (s[i] == ' ' || s[i] == '\t'))
	new_s[j++] = ' ';
      i++;
    }
  if (new_s[j] == ' ')
    new_s[j] = '\0';
  return (new_s);
}
