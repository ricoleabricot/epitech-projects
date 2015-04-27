/*
** string.c for minitalk in /home/gicque_p/local/unix/PSU_2013_minitalk
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 11 14:06:38 2014 Pierrick Gicquelais
** Last update Wed Mar 19 20:03:01 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>
#include	"minitalk.h"

int		my_getnbr(char *str)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  if (str[0] && str[0] == '-')
    i++;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      n = n + str[i] - 48;
      n = n * 10;
      i++;
    }
  n /= 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}

char		*my_strcpy(char *str, int i)
{
  time_t	timep;
  char		*cur_time;
  int		j;

  j = 0;
  timep = time(&timep);
  cur_time = ctime(&timep);
  while (cur_time[j])
    str[i++] = cur_time[j++];
  return (str);
}

char		*my_strcat(char *dest, char *src)
{
  char		*str;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  if ((str = malloc							\
       ((my_strlen(src) + my_strlen(dest) + 2) * sizeof(char))) == NULL)
    my_error("Error 124: Error with a memory allocation", 124);
  while (dest[i])
    str[k++] = dest[i++];
  while (src[j])
    str[k++] = src[j++];
  str[k] = '\0';
  return (str);
}
