/*
** is_reply.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 21:32:59 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:14:49 2015 Pierrick Gicquelais
*/

#include	"is_reply.h"

static char	(*g_str[6]) =
{
  NICK,
  JOIN,
  PART,
  SEND,
  ACCEPT,
  NULL
};

bool		is_reply(char *str)
{
  int		i;

  i = 0;
  if (strlen(str) > 8)
    {
      if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && \
	  str[4] == 'R' && str[5] == 'P' && str[6] == 'L')
	return (true);
      else if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && \
	  str[4] == ':')
	return (true);
      else if (str[0] == ':')
	return (true);
    }

  while (g_str[i] && strncmp(g_str[i], str, strlen(g_str[i])) != 0)
    i++;

  if (g_str[i])
    return (true);
  return (false);
}
