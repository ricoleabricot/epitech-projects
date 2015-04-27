/*
** destroy.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 13:16:00 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:52:05 2015 Pierrick Gicquelais
*/

#include	"destroy_client.h"

void		disconnect(t_client *cli)
{
  if (cli->ip != NULL)
    free(cli->ip);
  if (cli->port != NULL)
    free(cli->port);
  if (cli->nick != NULL)
    free(cli->nick);
  if (cli->ch != NULL)
    free(cli->ch);
  if (cli->filename != NULL)
    free(cli->filename);
  cli->is_connected = false;
}

void		destroy(t_client *cli)
{
  disconnect(cli);
  close(cli->fd);
  free(cli);
}
