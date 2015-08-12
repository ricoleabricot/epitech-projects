/*
** commands_graphic.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:12:36 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:43:10 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static char	(*g_str[10]) =
{
  MAP_SIZE,
  CASE_CONTENT,
  MAP_CONTENT,
  TEAMS_NAME,
  PLAYER_POSITION,
  PLAYER_LEVEL,
  PLAYER_INVENT,
  GET_DELAY,
  SET_DELAY,
  NULL
};

static void	(*g_fct[13])(t_server *, t_client *, char *) =
{
  &map_size,
  &case_content,
  &map_content,
  &teams_name,
  &player_position,
  &player_level,
  &player_inventory,
  &get_delay,
  &set_delay,
  NULL
};

void		commands_graphic(t_server *server, t_client *client, char *s)
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
		client->messages = append_list(client->messages, strdup("suc\n"));
	      free(cmd);
	    }
	  free(str);
	}
    }
}
