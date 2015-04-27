/*
** encryption.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Mar 18 09:48:06 2015 Pierrick Gicquelais
** Last update Wed Mar 18 11:30:52 2015 Pierrick Gicquelais
*/

#include	"encryption.h"
#include	"xmalloc.h"

char	*encryption(char *password)
{
  char		*ret;
  int		i;
  int		len;

  ret = xmalloc(strlen(password) * sizeof(char));
  len = strlen(password);
  i = 0;
  while (i < len)
    {
      ret[i] = password[i] + (i % 10);
      i++;
    }

  return (ret);
}
