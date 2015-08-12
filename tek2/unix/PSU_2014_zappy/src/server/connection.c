/*
** connection.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 14:27:16 2015 Pierrick Gicquelais
** Last update Fri Jul  3 09:49:30 2015 Pierrick Gicquelais
*/

#include	"server/connection.h"

static t_client	*goodbye(t_server *server, char *str, int s)
{
  swrite(s, str);
  server->clients = pop_client(server->clients, s);

  return (server->clients);
}

static t_client	*hello(t_server *server, int s, char fd, fct_r fct_read)
{
  t_client	*client;

  client = get_client_by_socket(server->clients, s);
  client->fd_type = fd;
  client->fct_read = fct_read;

  return (server->clients);
}

static t_client	*accept_team(t_server *server, t_team *team, int s)
{
  t_client	*client;
  char		*str;

  server->clients = hello(server, s, FD_CLIENT, client_read);
  client = get_client_by_socket(server->clients, s);
  client->team = strdup(team->name);
  team->clients++;

  asprintf(&str, "%d\n", server->max_clients - team->clients);
  client->messages = append_list(client->messages, strdup(str));
  free(str);

  asprintf(&str, "%d %d\n", server->width, server->height);
  client->messages = append_list(client->messages, strdup(str));
  free(str);

  server->clients = check_egg(server, client);
  new_connection(server, client);

  generate_resources(server->map);

  if (server->verbose == true)
    verbose_connection(client);

  return (server->clients);
}

static t_client	*check_client(t_server *server, char *name, \
			      char *str, int s)
{
  t_team	*team;

  if ((team = find_team_by_name(server->teams, name)) != NULL)
    {
      if (team->clients < server->max_clients)
	{
	  server->clients = accept_team(server, team, s);
	  buffering(server, str, s);
	}
      else
	server->clients = goodbye(server, "Team is full\n", s);
    }
  else if (strcmp(str, "GRAPHIC") == 0)
    {
      server->clients = hello(server, s, FD_GRAPHIC, graphic_read);
      graphic_connection(server, s);
    }
  else
    server->clients = goodbye(server, "Teamname doesn't exists\n", s);

  return (server->clients);
}

t_client	*check_connection(t_server *server, int s)
{
  char		buf[512];
  char		*str;
  char		*name;

  memset(buf, 0, 512);
  read(s, buf, 512);

  if (buf[0] != 0 && buf[0] != 10)
    {
      str = trim(buf);
      name = split_string(str, '\n', 0);
      if (name != NULL)
	{
	  check_client(server, name, str, s);
	  free(name);
	}
      free(str);
    }
  else
    server->clients = goodbye(server, "Teamname cannot be empty\n", s);

  return (server->clients);
}
