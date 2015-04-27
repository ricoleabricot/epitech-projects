/*
** user_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:39:28 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:35:12 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"user.h"
#include	"channel.h"
#include	"op.h"
#include	"split_string.h"
#include	"swrite.h"

void	        users(t_server *serv, t_user *user, char *cmd)
{
  (void)cmd;
  swrite(user->fd, "392 RPL_USERSTART :UserID Terminal hôte\r\n");
  aff_users(serv->users, user->nick, user->fd);
  swrite(user->fd, "394 RPL_ENDOFUSERS :End of /USERS\r\n");
}

static bool	check_values(char *username, char *host, char *servername, \
			     char *realname)
{
  if (username == NULL || strlen(username) > 64)
    return (false);
  else if (host == NULL || strlen(host) > 64)
    return (false);
  else if (servername == NULL || strlen(servername) > 64)
    return (false);
  else if (realname == NULL || strlen(realname) > 64)
    return (false);
  return (true);
}

void		user(t_server *serv, t_user *user, char *cmd)
{
  char		*username;
  char		*host;
  char		*servername;
  char		*realname;

  (void)serv;
  username = split_string(cmd, ' ', 1);
  host = split_string(cmd, ' ', 2);
  servername = split_string(cmd, ' ', 3);
  realname = split_string(cmd, ' ', 4);
  if (check_values(username, host, servername, realname))
    {
      user->username = strdup(username);
      user->host = strdup(host);
      user->servername = strdup(servername);
      user->realname = strdup(realname);

      free(username);
      free(host);
      free(servername);
      free(realname);
    }
  else
    swrite(user->fd, "461 :Not enough parameters\r\n");
}

void		me(t_server *serv, t_user *user, char *cmd)
{
  char		ret[512];

  (void)serv;
  (void)cmd;
  sprintf(ret, "371 RPL_INFO :Nick: %s\r\n", user->nick);
  swrite(user->fd, ret);
  sprintf(ret, "371 RPL_INFO :Channel: %s\r\n", \
	  (user->ch != NULL) ? user->ch : "Not in a channel");
  swrite(user->fd, ret);
  sprintf(ret, "371 RPL_INFO :Username: %s\r\n", \
	  (user->username != NULL) ? user->username : "Not specified");
  swrite(user->fd, ret);
  sprintf(ret, "371 RPL_INFO :Host: %s\r\n", \
	  (user->host != NULL) ? user->host : "Not specified");
  swrite(user->fd, ret);
  sprintf(ret, "371 RPL_INFO :Servername: %s\r\n", \
	  (user->servername != NULL) ? user->servername : "Not specified");
  swrite(user->fd, ret);
  sprintf(ret, "371 RPL_INFO :Realname: %s\r\n", \
	  (user->realname != NULL) ? user->realname : "Not specified");
  swrite(user->fd, ret);
  swrite(user->fd, "374 RPL_ENDOFINFO :End of /ME list\r\n");
}
