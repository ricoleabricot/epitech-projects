/*
** commands_client.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:12:36 2015 Pierrick Gicquelais
** Last update Mon Jun 29 14:15:03 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"

static char	(*g_str[13]) =
{
  FORWARD,
  LEFT,
  RIGHT,
  SEE,
  INVENTORY,
  TAKE_OBJ,
  PUT_OBJ,
  EXPULSE,
  SPEAKING,
  SPELL,
  FORK,
  CONNECT_NUMBER,
  NULL
};

static void	(*g_fct[13])(t_server *, t_client *, char *) =
{
  &forward,
  &left,
  &right,
  &see,
  &inventory,
  &take_obj,
  &put_obj,
  &expulse,
  &speaking,
  &spell,
  &fork_client,
  &connect_number,
  NULL
};

void		commands_client(t_server *server, t_client *client, char *s)
{
  char		*str;
  char		*cmd;
  int		i;

  i = 0;
  if (s[0] && s[0] != 10)
    {
      str = trim(s);
      if (str)
	{
	  cmd = split_string(str, ' ', 0);
	  if (cmd)
	    {
	      while (g_str[i] && strcmp(g_str[i], cmd) != 0)
		i++;
	      if (g_str[i] != NULL)
		g_fct[i](server, client, str);
	      else
		client->messages = append_list(client->messages, \
					       strdup("Unknown command\n"));
	      free(cmd);
	    }
	  free(str);
	}
    }
}
