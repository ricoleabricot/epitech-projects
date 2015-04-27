/*
** trim.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:07 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:07 2015 Pierrick Gicquelais
*/

#include	"trim.h"

char		*trim(char * s)
{
  int		l;

  l = strlen(s);
  while (isspace(s[l - 1]))
    --l;
  while (*s && isspace(*s))
    {
      ++s;
      --l;
    }

  return (strndup(s, l));
}
