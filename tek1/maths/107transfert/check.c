/*
** check.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar  6 15:23:56 2014 Pierrick Gicquelais
** Last update Thu Mar  6 16:47:32 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

int		check_env(char **envp)
{
  int		i;
  int		flag;

  i = 0;
  flag = 0;
  while (envp[i])
    if (strncmp("DISPLAY=", envp[i++], 8) == 0)
      flag = 1;
  return (flag);
}

int		check_string(char *str)
{
  int           i;
  int           pipe;

  i = 0;
  pipe = 0;
  while (str[i])
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	i++;
      else if (str[i] == '|')
	{
	  if (((str[i + 1] >= '0' && str[i + 1] <= '9') ||		\
	       str[i + 1] == '-') && (str[i - 1] >= '0' && str[i - 1] <= '9'))
	    {
	      pipe++;
	      i++;
	    }
	  else
	    char_error(i + 1);
	}
      else
	char_error(i + 1);
    }
  return (pipe + 1);
}
