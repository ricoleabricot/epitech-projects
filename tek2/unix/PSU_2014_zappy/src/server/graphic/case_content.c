/*
** case_content.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/graphic
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 26 14:28:03 2015 Pierrick Gicquelais
** Last update Sun Jun 28 13:52:48 2015 Pierrick Gicquelais
*/

#include	"server/commands_graphic.h"

static void	print_resources(t_client *client, t_case *pos, int x, int y)
{
  char		*s;
  int		*res;

  res = pos->resources;
  asprintf(&s, "bct %d %d %d %d %d %d %d %d %d\n", x, y, res[FOOD], \
	   res[LINEMATE], res[DERAUMERE], res[SIBUR], \
	   res[MENDIANE], res[PHIRAS], res[THYSTAME]);
  client->messages = append_list(client->messages, strdup(s));
  free(s);
}

void		case_content(t_server *server, t_client *client, char *str)
{
  t_case	*pos;
  char		*x;
  char		*y;

  if ((x = split_string(str, ' ', 1)) != NULL)
    {
      if ((y = split_string(str, ' ', 2)) != NULL)
	{
	  pos = find_case_by_index(server->map, atoi(x), atoi(y));
	  if (pos != NULL)
	    print_resources(client, pos, atoi(x), atoi(y));
	  else
	    client->messages = append_list(client->messages, strdup("sbp\n"));
	  free(y);
	}
      else
	client->messages = append_list(client->messages, strdup("sbp\n"));
      free(x);
    }
  else
    client->messages = append_list(client->messages, strdup("sbp\n"));
}
