/*
** trim.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 18:26:29 2015 Pierrick Gicquelais
** Last update Fri Jun 19 18:28:38 2015 Pierrick Gicquelais
*/

#include	"server/trim.h"

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
