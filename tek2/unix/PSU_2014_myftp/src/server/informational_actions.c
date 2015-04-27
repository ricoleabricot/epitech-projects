/*
** informational_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 27 11:41:58 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:17:46 2015 Pierrick Gicquelais
*/

#include	"actions.h"
#include	"do_actions_server.h"
#include	"split_string.h"
#include	"swrite.h"

static	char	(*g_str[22]) =
{
  USER,
  PASS,
  DISCONNECT,
  SETUSER,
  LS,
  LIST,
  CD,
  CWD,
  MKDIR,
  GET,
  RETR,
  PUT,
  STOR,
  PWD,
  HELP,
  WHY,
  TYPE,
  PASV,
  PORT,
  NOOP,
  QUIT,
  NULL
};

static	char	(*g_ret[22]) =
{
  "214 Define new session on the local machine | USER 'username'\r\n",
  "214 Enter the password for the actual session | PASS 'password'\r\n",
  "214 Quit actual user session\r\n",
  "214 Set a new user in the database | SETUSER 'username' 'password'\r\n",
  "214 List files in the current remote directory\r\n",
  "214 List files in the current remote directory\r\n",
  "214 Change directory on the remote machine | CD 'pathname'\r\n",
  "214 Change directory on the remote machine | CWD 'pathname'\r\n",
  "214 Make a directory in the current remote directory | MKDIR 'name'\r\n",
  "214 Copy one file from remote machine to local machine | PUT 'file'\r\n",
  "214 Copy one file from remote machine to local machine | STOR 'file'\r\n",
  "214 Copy one file from local machine to remote machine | GET 'file'\r\n",
  "214 Copy one file from local machine to remote machine | RETR 'file'\r\n",
  "214 Print the pathname of the current remote directory\r\n",
  "214 Return help on using the server\r\n",
  "214 Return help on using the server\r\n",
  "214 Set transfert type | TYPE 'value'\r\n",
  "214 Enter passive mode\r\n",
  "214 Open a data port | PORT 'dataport'\r\n",
  "214 Returns command okay\r\n",
  "214 Terminate a communication\r\n",
  NULL
};

void		help(t_server *serv, char *cmd)
{
  char		*token;
  int		i;

  token = split_string(cmd, ' ', 1);
  if (token != NULL)
    {
      i = 0;
      while (g_str[i] && strcasecmp(token, g_str[i]))
	i++;
      if (g_str[i])
	swrite(serv->cfd, g_ret[i]);
      else
	swrite(serv->cfd, "214 Entry not existing in manual\r\n");
      free(token);
    }
  else
    swrite(serv->cfd, "214 Lists of commands: USER, PASS, DISCONNECT, \
SETUSER, LS, LIST, CD, CWD, MKDIR, GET, RETR, PUT, STOR, PWD, HELP, ?, TYPE, \
PASV, PORT, NOOP, QUIT\r\n");
}
