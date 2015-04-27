/*
** do_actions.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Mar 21 15:38:23 2015 Pierrick Gicquelais
** Last update Sat Mar 28 22:27:58 2015 Pierrick Gicquelais
*/

#include	"do_actions_client.h"
#include	"transfert.h"
#include	"list.h"
#include	"split_string.h"
#include	"xmalloc.h"
#include	"swrite.h"

static	char	(*g_str[8]) =
{
  STOR,
  PUT,
  RETR,
  GET,
  LIST,
  LS,
  RLS,
  NULL
};

static	void	(*g_fct[8])(t_client *, char *) =
{
  &upload,
  &upload,
  &download,
  &download,
  &list,
  &list,
  &rlist,
  NULL
};

void		do_actions(t_client *cli, char *cmd)
{
  char		*token;
  bool	        lwrite;
  int		i;

  token = split_string(cmd, ' ', 0);
  lwrite = false;
  if (token != NULL)
    {
      i = 0;
      while (g_str[i] && strcasecmp(token, g_str[i]) != 0)
	i++;
      if (g_str[i] && cli->login == true)
	(g_fct[i])(cli, cmd);
      else
	lwrite = true;
      free(token);
    }

  if (lwrite == true)
    swrite(cli->fd, cmd);
}
