/*
** connection.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 16:18:26 2015 Pierrick Gicquelais
** Last update Sat Apr 11 18:33:57 2015 Pierrick Gicquelais
*/

#include	"connection.h"
#include	"init_client.h"
#include	"destroy_client.h"
#include	"getnextline.h"
#include	"split_string.h"
#include	"swrite.h"

static void	get_new_connection(t_client *cli, char *cmd)
{
  char		*data;

  data = split_string(cmd, ' ', 1);
  if (data != NULL)
    {
      cli->ip = split_string(data, ':', 0);
      cli->port = split_string(data, ':', 1);
      init(cli);
      free(data);
    }
  else
    printf("./server <machine:port> ; connect to a server\n");
}

void		connection(t_client *cli, char *s)
{
  char		*token;

  token = split_string(s, ' ', 0);
  if (token != NULL)
    {
      if (strcasecmp(token, "/server") == 0)
	{
	  if (!cli->is_connected)
	    get_new_connection(cli, s);
	}
      else if (!cli->is_connected)
	printf("You're not connected\n");
      free(token);
    }
}
