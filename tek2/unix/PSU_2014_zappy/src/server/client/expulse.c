/*
** expulse.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jun 22 17:25:18 2015 Pierrick Gicquelais
** Last update Mon Jun 29 20:53:32 2015 rousse_3
*/

#include	"server/commands_client.h"

void		expulse(t_server *server, t_client *client, char *str)
{
  t_list	*tmp;
  t_list	*next;
  t_case	*cas;
  int		x;
  int		y;

  (void)str;
  get_new_pos(server, client->player, &x, &y);
  cas = find_case_by_index(server->map, client->player->x, client->player->y);
  if (cas && cas->player && cas->player->next)
    {
      tmp = cas->player;
      while (tmp)
	{
	  next = tmp->next;
	  if (tmp->data != client->player)
	    move_player_to_pos(server->map, tmp->data, x, y);
	  tmp = next;
	}
      player_expulse(server, client);
      client->messages = append_list(client->messages, strdup("ok\n"));
    }
  else
    client->messages = append_list(client->messages, strdup("ko\n"));
  client->player->delay_action = (7.f / server->delay) * 1000000;
}
