/*
** get_command.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 19:00:11 2015 Pierrick Gicquelais
** Last update Sat Apr 11 19:04:00 2015 Pierrick Gicquelais
*/

#include	"get_command.h"
#include	"xmalloc.h"

static int	skip_spaces(char *s)
{
  int		i;

  i = 0;
  while (s[i] && isspace(s[i]))
    i++;

  return (i);
}

char		*get_command(char *s)
{
  char          *cmd;
  int           i;
  int           j;

  cmd = xmalloc((strlen(s) + 1) * sizeof(char));
  i = skip_spaces(s);
  j = 0;
  if (s[i] && s[i] == '/')
    {
      i++;
      while (s[i] && s[i] != ' ')
	{
	  cmd[j] = toupper(s[i]);
	  i++;
	  j++;
	}
    }
  while (s[i])
    {
      cmd[j] = s[i];
      i++;
      j++;
    }
  cmd[j] = 0;
  return (cmd);
}
