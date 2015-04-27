/*
** wreturn.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 18:07:51 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:23:30 2015 Pierrick Gicquelais
*/

#include	"wreturn.h"
#include	"split_string.h"
#include	"protocol.h"
#include	"file_client.h"
#include	"trim.h"
#include	"is_reply.h"
#include	"is_error.h"
#include	"swrite.h"

void		rreturn(t_client *cli)
{
  int		length;
  int		i;

  length = 0;
  i = 0;
  if (cli->nick != NULL)
    length += strlen(cli->nick);
  if (cli->ch != NULL)
    length += strlen(cli->ch);
  else
    length += strlen("KafeIRC");

  while (i < length)
    {
      write(1, "\b", 1);
      write(1, " ", 1);
      write(1, "\b", 1);
      i++;
    }
}

void		freturn(char *buf)
{
  char		ret[512];
  char		*newbuf;
  char		*nick;
  char		*say;

  write(1, "\r", 1);
  if (strstr(buf, "PRIVMSG") != NULL)
    {
      newbuf = split_string(buf, ':', 1);
      nick = split_string(newbuf, ' ', 0);
      say = split_string(buf, ':', 2);
      sprintf(ret, "\033[01m%s: %s", nick, say);

      free(newbuf);
      free(nick);
      free(say);
    }
  else if (is_reply(buf))
    sprintf(ret, "\033[93m%s", buf);
  else if (is_error(buf))
    sprintf(ret, "\033[31m%s", buf);
  else
    sprintf(ret, "\033[01m%s", buf);
  swrite(1, ret);
  swrite(1, "\033[0m");
}

static void	second_wreturn(t_client *cli, char *buf)
{
  if (strncmp(SEND, buf, 9) == 0)
    {
      pasv(cli, buf);
      send_file(cli, buf);
    }
  else if (strncmp(ACCEPT, buf, 11) == 0)
    {
      pasv(cli, buf);
      FD_SET(cli->sf, &cli->fd_read);
      cli->filename = split_string(buf, ':', 1);
    }
}

void		wreturn(t_client *cli, char *buf)
{
  char		*nick;
  char		*ch;

  if (strncmp(NICK, buf, 4) == 0)
    {
      nick = split_string(buf, ' ', 1);
      cli->nick = split_string(nick, '\r', 0);
      free(nick);
    }
  else if (strncmp(JOIN, buf, 4) == 0)
    {
      ch = split_string(buf, ' ', 1);
      cli->ch = split_string(ch, '\r', 0);
      free(ch);
    }
  else if (strncmp(PART, buf, 4) == 0)
    cli->ch = NULL;
  else
    second_wreturn(cli, buf);
}
