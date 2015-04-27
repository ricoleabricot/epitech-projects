/*
** encryption.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar 18 09:48:06 2015 Pierrick Gicquelais
** Last update Fri Apr 10 16:00:25 2015 Pierrick Gicquelais
*/

#include	"encryption.h"
#include	"xmalloc.h"

char		*encryption(char *password)
{
  char		*ret;
  int		i;
  int		len;

  ret = xmalloc((strlen(password) + 1) * sizeof(char));
  len = strlen(password);
  i = 0;
  while (i < len)
    {
      ret[i] = password[i] + (i % 10);
      i++;
    }
  ret[i] = '\0';

  return (ret);
}
