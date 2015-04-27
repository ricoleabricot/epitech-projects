/*
** trim.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Mar 21 13:13:27 2015 Pierrick Gicquelais
** Last update Sat Mar 21 13:28:41 2015 Pierrick Gicquelais
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
