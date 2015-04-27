/*
** help_commands.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 27 11:41:58 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:57:38 2015 Pierrick Gicquelais
*/

#include	"commands.h"
#include	"split_string.h"
#include	"swrite.h"

static  char    (*g_str[24]) =
{
  SERVER,
  NICK,
  LIST,
  JOIN,
  PART,
  USERS,
  PRIVMSG,
  MSG,
  SEND,
  ACCEPT,
  OPER,
  DEOPER,
  KICK,
  KILL,
  CREATE,
  INVITE,
  MODE,
  PASS,
  USER,
  ME,
  TOPIC,
  HELP,
  QUIT,
  NULL
};

static	char	(*g_ret[24]) =
{
  "314 RPL_HELP :/server <servername:port> ; connect to server\r\n",
  "314 RPL_HELP :/nick <nickname> (<password>) ; change nickname\r\n",
  "314 RPL_HELP :/list (<channel>) ; list matched channels\r\n",
  "314 RPL_HELP :/join <channel> ; join a channel\r\n",
  "314 RPL_HELP :/part ; leave a channel\r\n",
  "314 RPL_HELP :/users ; list all users in channel\r\n",
  "314 RPL_HELP :/privmsg <nickname> <message> ; message a special user\r\n",
  "314 RPL_HELP :/msg <nickname> <message> ; message a special user\r\n",
  "314 RPL_HELP :/send_file <nick> <name> ; send a file to special user\r\n",
  "314 RPL_HELP :/accept_file <nick> ; accept file from special user\r\n",
  "314 RPL_HELP :/oper <nickname> ; give special user OP rights\r\n",
  "314 RPL_HELP :/deoper <nickname> ; retrieve special user OP rights\r\n",
  "314 RPL_HELP :/kick <nickname> <reason> ; kick special user\r\n",
  "314 RPL_HELP :/kill <nickname> <reason> ; force quit an user\r\n",
  "314 RPL_HELP :/create <channel> ; create a channel\r\n",
  "314 RPL_HELP :/invite <nick> ; invite a special user to join channel\r\n",
  "314 RPL_HELP :/mode 0|1 ; set channel to mode public or private\r\n",
  "314 RPL_HELP :/pass <password> ; set a password for nickname\r\n",
  "314 RPL_HELP :/user <name> <host> <servname> <realname> ; give infos\r\n",
  "314 RPL_HELP :/me ; list informations about you\r\n",
  "314 RPL_HELP :/topic <name>; print or set channel topic\r\n",
  "314 RPL_HELP :/help ; print this help\r\n",
  "314 RPL_HELP :/quit ; close connection from client to server\r\n",
  NULL
};

void		help(t_server *serv, t_user *user, char *cmd)
{
  char		*token;
  int		i;

  (void)serv;
  token = split_string(cmd, ' ', 1);
  if (token != NULL)
    {
      i = 0;
      while (g_str[i] && strcasecmp(token, g_str[i]))
	i++;
      if (g_str[i])
	swrite(user->fd, g_ret[i]);
      else
	swrite(user->fd, "314 Entry not existing in manual\r\n");
      free(token);
    }
  else
    swrite(user->fd, "314 RPL_HELP :Lists of commands: SERVER, NICK, LIST, \
JOIN, PART, USERS, PRIVMSG, MSG, SEND_FILE, ACCEPT_FILE, OPUSERS, OP, DEOP, \
KICK, CREATE, INVITE, MODE, PASS, USER, TOPIC, ME, HELP, QUIT\r\n");
}
