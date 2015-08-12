/*
** read.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Jun 19 09:42:40 2015 Pierrick Gicquelais
** Last update Sun Jul  5 21:25:06 2015 Pierrick Gicquelais
*/

#include	"server/read.h"

t_client	*verify_read(t_server *server, int s)
{
  server->clients = check_connection(server, s);

  return (server->clients);
}

t_client	*graphic_read(t_server *server, int s)
{
  t_client	*client;
  char		buf[512];
  int		r;

  client = get_client_by_socket(server->clients, s);
  memset(buf, 0 , 512);
  if ((r = read(s, buf, 512)) > 0 && (client->buf_size + r) < 512)
    {
      client->buf_size += r;
      strcat(client->buf, buf);
      if (client->buf[strlen(client->buf) - 1] == 10)
	{
	  client->buf[strlen(client->buf)] = 0;

	  if (server->verbose == true)
	    verbose_read(client);

	  commands_graphic(server, client, client->buf);
	  memset(client->buf, 0, 512);
	  client->buf_size = 0;
	}
    }

  return (server->clients);
}

static t_client	*client_listen(t_server *server, t_client *client, \
			       char *buf, int r)
{
  client->buf_size += r;
  strcat(client->buf, buf);
  if (client->buf[strlen(client->buf) - 1] == 10)
    {
      client->buf[strlen(client->buf)] = 0;
      if (list_size(client->player->actions) < 10 && client->buf[0] && \
	  client->buf[0] != 10)
	{
	  client->player->actions = append_list(client->player->actions, \
						strdup(client->buf));
	  if (server->verbose == true)
	    verbose_read(client);
	}
      memset(client->buf, 0, 512);
      client->buf_size = 0;
    }

  return (server->clients);
}

t_client	*client_read(t_server *server, int s)
{
  t_team	*team;
  t_client	*client;
  char		buf[512];
  int		r;

  client = get_client_by_socket(server->clients, s);
  memset(buf, 0 , 512);
  if ((r = read(s, buf, 512)) > 0 && (client->buf_size + r) < 512)
    server->clients = client_listen(server, client, buf, r);
  else
    {
      team = find_team_by_name(server->teams, client->team);
      team->clients--;
      player_dead(server, client);
      server->clients = pop_client(server->clients, s);
    }
  return (server->clients);
}

t_client	*server_read(t_server *server, int s)
{
  struct sockaddr_in	csin;
  socklen_t		len;
  int			cs;

  len = sizeof(csin);
  cs = xaccept(s, (struct sockaddr *)&csin, &len);

  printf("New connection from fd n°%d\n", cs);
  swrite(cs, "BIENVENUE\n");

  server->clients = append_client(server->clients, cs, FD_VERIFY, verify_read);

  return (server->clients);
}
