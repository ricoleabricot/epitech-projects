/*
** see.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
* Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Sun Jul  5 12:25:04 2015 Pierrick Gicquelais
*/

#include	"server/commands_client.h"
#include	"server/server.h"
#include	"server/see.h"

void		aply_dx(t_client *client, int *x, int dy)
{
  if (client->player->orientation == NORTH || \
      client->player->orientation == SOUTH)
    (*x) -= dy;
}

void		aply_dy(t_client *client, int *y, int dx)
{
  if (client->player->orientation == EAST || \
      client->player->orientation == WEST)
    (*y) += dx;
}

char		*print_line(char *str, char *tmp, int lvl, int cas)
{
  char		*old_str;

  old_str = str;
  if (cas == (2 * lvl + 1))
    asprintf(&str, "%s", tmp);
  else
    asprintf(&str, "%s,%s", str, tmp);
  if (tmp)
    free(tmp);
  if (old_str)
    free(old_str);
  return (str);
}

char		*print_see(char *string, char *tmp, int lvl, int max_lvl)
{
  if (lvl == 0)
    asprintf(&string, "{%s", tmp);
  else if (lvl == max_lvl)
    asprintf(&string, "%s,%s}\n", string, tmp);
  else
    asprintf(&string, "%s,%s", string, tmp);
  return (string);
}

void		see(t_server *server, t_client *client, char *str)
{
  int		lvl;
  char		*old_string;
  char		*string;
  char		*tmp;

  string = xmalloc(1);
  lvl = 0;
  (void)str;
  while (lvl <= client->player->level)
    {
      old_string = string;
      tmp = get_line(server, client, lvl, 2 * lvl + 1);
      string = print_see(string, tmp, lvl, client->player->level);
      if (old_string)
	free(old_string);
      if (tmp)
	free(tmp);
      ++lvl;
    }
  client->player->delay_action = (7.f / server->delay) * 1000000;
  client->messages = append_list(client->messages, strdup(string));
  free(string);
}
