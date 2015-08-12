/*
** client.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 15:55:47 2015 Pierrick Gicquelais
** Last update Wed Jul  1 11:44:36 2015 Pierrick Gicquelais
*/

#include	"server/client.h"

t_client	*new_client(void)
{
  t_client	*new;

  new = xmalloc(sizeof(t_client));

  new->prev = NULL;
  new->next = NULL;

  new->socket = 0;
  new->parent = 0;
  new->team = NULL;

  memset(new->buf, 0, 512);
  new->buf_size = 0;
  new->messages = NULL;

  new->fd_type = FD_FREE;
  new->fct_read = NULL;
  new->fct_write = NULL;

  new->player = NULL;

  return (new);
}

t_client	*append_client(t_client *old, int socket, char type, \
				       fct_r fct_read)
{
  t_client	*new;

  new = new_client();
  if ((old = last_client(old)) != NULL)
    old->next = new;

  new->prev = old;
  new->next = NULL;

  new->socket = socket;
  new->fd_type = type;
  new->fct_read = fct_read;
  new->fct_write = client_write;

  return (new);
}

t_client	*first_client(t_client *clients)
{
  if (clients != NULL)
    while (clients->prev != NULL)
      clients = clients->prev;
  return (clients);
}

t_client	*last_client(t_client *clients)
{
  if (clients != NULL)
    while (clients->next != NULL)
      clients = clients->next;
  return (clients);
}

t_client	*get_client_egg_by_team(t_client *clients, char *team)
{
  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type == FD_FREE)
	{
	  if (strcmp(clients->team, team) == 0)
	    return (clients);
	}
      clients = clients->next;
    }
  return (NULL);
}
