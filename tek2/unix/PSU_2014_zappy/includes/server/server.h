/*
** server.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/includes/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:50:42 2015 Pierrick Gicquelais
** Last update Thu Jul  2 13:02:48 2015 Pierrick Gicquelais
*/

#ifndef		SERVER_H_
# define	SERVER_H_

# include	<stdbool.h>

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<sys/socket.h>
# include	<sys/time.h>

# include	<arpa/inet.h>
# include	<netinet/in.h>

# include	"team.h"
# include	"client.h"
# include	"list.h"
# include	"case.h"
# include	"map.h"
# include	"player.h"
# include	"broadcast.h"
# include	"pos.h"

typedef struct	s_server	t_server;
struct		s_server
{
  int		port;
  int		width;
  int		height;
  t_team	*teams;
  int		max_clients;
  int		delay;
  bool		verbose;

  t_list	*map;
  t_client	*clients;

  bool		end;
};

#endif		/* SERVER_H_ */
