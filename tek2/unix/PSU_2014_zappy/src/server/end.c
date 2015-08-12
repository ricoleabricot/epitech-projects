/*
** end.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jul  2 12:56:44 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:10:06 2015 Pierrick Gicquelais
*/

#include	"server/end.h"

void		end_game(t_server *server, t_client *clients, t_client *tmp)
{
  char		*s;

  clients = first_client(clients);
  while (clients)
    {
      if (clients->fd_type == FD_CLIENT)
	{
	  if (strcmp(clients->team, tmp->team) == 0)
	    clients->messages = append_list(clients->messages, \
					    strdup("Your team won\n"));
	  else
	    clients->messages = append_list(clients->messages, \
					    strdup("Your team lost\n"));
	}
      else if (clients->fd_type == FD_GRAPHIC)
	{
	  asprintf(&s, "seg %s\n", tmp->team);
	  clients->messages = append_list(clients->messages, strdup(s));
	  free(s);
	}
      clients = clients->next;
    }

  server->end = true;
}
