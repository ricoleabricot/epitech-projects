/*
** do_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/client
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 19:13:25 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:24:55 2015 Pierrick Gicquelais
*/

#include	"do_actions_server.h"
#include	"actions.h"
#include	"trim.h"
#include	"split_string.h"
#include	"swrite.h"
#include	"merror.h"

static  char    (*g_str[24]) =
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
  DELE,
  RM,
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

static	void	(*g_fct[24])(t_server *, char *) =
{
  &user,
  &pass,
  &disconnect,
  &setuser,
  &ls,
  &ls,
  &cd,
  &cd,
  &makedir,
  &get,
  &get,
  &put,
  &put,
  &rm,
  &rm,
  &pwd,
  &help,
  &help,
  &type,
  &pasv,
  &port,
  &noop,
  &quit,
  NULL
};

static void	action_it(t_server *serv, char *cmd, int i)
{
  if (g_str[i])
    {
      if (serv->login == false && (i >= 2 && i <= 13))
	swrite(serv->cfd, "530 You need to be logged in\n");
      else
	(g_fct[i])(serv, cmd);
    }
  else
    unknown(serv, cmd);
}

void		do_actions(t_server *serv, char *cmd)
{
  char		*trimstr;
  char		*token;
  int		i;

  i = 0;
  trimstr = trim(cmd);
  if (trimstr[0])
    {
      token = split_string(trimstr, ' ', 0);
      if (token != NULL)
	{
	  while (g_str[i] && strcasecmp(g_str[i], token) != 0)
	    i++;
	  action_it(serv, trimstr, i);
	  free(token);
	}
    }
  else
    unknown(serv, trimstr);
  free(trimstr);
}
