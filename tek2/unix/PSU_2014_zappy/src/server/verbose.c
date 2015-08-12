/*
** verbose.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 13:27:48 2015 Pierrick Gicquelais
** Last update Wed Jul  1 12:38:53 2015 Pierrick Gicquelais
*/

#include	"server/verbose.h"

void		aff_server(t_server *server)
{
  printf("Server Port: %d\n", server->port);
  printf("Server Map Width: %d\n", server->width);
  printf("Server Map Height: %d\n", server->height);
  printf("Server Teams:\n");
  aff_teams(server->teams);
  printf("Server Max Clients: %d\n", server->max_clients);
  printf("Server Delay Time: %d\n", server->delay);
}

void		verbose_connection(t_client *client)
{
  if (client->fd_type == FD_GRAPHIC)
    printf("Client id #%d becomes a graphic client\n", client->socket);
  else if (client->fd_type == FD_CLIENT)
    printf("Client id #%d becomes a client in team: %s\n", client->socket, \
	   client->team);
}

void		verbose_read(t_client *client)
{
  char		*str;
  char		*s;

  s = trim(client->buf);
  if (s != NULL)
    {
      if (client->fd_type == FD_GRAPHIC)
	{
	  asprintf(&str, "<< Read from graphic id #%d: '%s'\n", \
		   client->socket, s);
	  logs(str, "graphic");
	}
      else
	{
	  asprintf(&str, "<< Read from client id #%d: '%s'\n", \
		   client->socket, s);
	  logs(str, "client");
	}
      free(s);
      free(str);
    }
}

void		verbose_write(t_client *client, char *msg)
{
  char		*str;
  char		*s;

  s = trim(msg);
  if (s != NULL)
    {
      if (client->fd_type == FD_GRAPHIC)
	{
	  asprintf(&str, ">> Write to graphic id #%d: '%s'\n", \
		   client->socket, s);
	  logs(str, "graphic");
	}
      else
	{
	  asprintf(&str, ">> Write to client id #%d: '%s'\n", \
		   client->socket, s);
	  logs(str, "client");
	}
      free(s);
      free(str);
    }
}
