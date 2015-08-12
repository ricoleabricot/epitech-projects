/*
** write.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jun 28 12:48:15 2015 Pierrick Gicquelais
** Last update Sun Jul  5 21:06:53 2015 Pierrick Gicquelais
*/

#include	"server/write.h"

t_client	*client_write(t_server *server, t_client *client, bool verbose)
{
  while (client->messages)
    {
      if (client->messages->data)
	{
	  if (swrite(client->socket, client->messages->data) == -1)
	    {
	      if (client->fd_type == FD_CLIENT)
		player_dead(server, client);
	      server->clients = pop_client(server->clients, client->socket);
	      break;
	    }

	  if (verbose == true)
	    verbose_write(client, client->messages->data);

	  free(client->messages->data);
	}
      client->messages = delete_list(client->messages);
    }

  return (server->clients);
}
