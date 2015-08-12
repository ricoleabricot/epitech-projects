/*
** client_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Jun 27 20:20:38 2015 Pierrick Gicquelais
** Last update Wed Jul  1 11:41:42 2015 Pierrick Gicquelais
*/

#include	"server/client.h"

static t_client *pop_element(t_client *client, t_client *tmp)
{
  if (client->prev == NULL && client->next != NULL)
    {
      client->next->prev = NULL;
      client = client->next;
    }
  else if (client->prev != NULL && client->next == NULL)
    {
      client->prev->next = NULL;
      client = client->prev;
    }
  else if (client->prev != NULL && client->next != NULL)
    {
      client->prev->next = tmp->next;
      client->next->prev = tmp->prev;
      client = client->prev;
    }
  else
    client = NULL;

  return (client);
}

t_client  *pop_client(t_client *clients, int fd)
{
  t_client  *tmp;

  clients = get_client_by_socket(clients, fd);

  if (clients != NULL)
    {
      tmp = clients;
      clients = pop_element(clients, tmp);

      if (tmp != NULL)
	free_client(tmp);
    }

  return (first_client(clients));
}

void		free_client(t_client *client)
{
  t_list	*tmp;

  if (client->team != NULL)
    free(client->team);

  if (client->messages != NULL)
    {
      tmp = ((t_list *)client->messages)->begin;
      while (tmp)
	{
	  free(tmp->data);
	  tmp->data = NULL;
	  tmp = tmp->next;
	}
      free_list(client->messages);
    }

  if (client->fd_type != FD_FREE)
    {
      close(client->socket);
      printf("Connection closed from fd n°%d\n", client->socket);
    }
  free(client);
}

void		free_clients(t_client *clients)
{
  t_client	*tmp;

  clients = first_client(clients);
  while (clients)
    {
      tmp = clients;
      clients = clients->next;
      free_client(tmp);
    }
}

t_client	*get_client_by_socket(t_client *clients, int socket)
{
  clients = first_client(clients);
  while (clients)
    {
      if (clients->socket == socket)
	return (clients);
      clients = clients->next;
    }
  return (NULL);
}
