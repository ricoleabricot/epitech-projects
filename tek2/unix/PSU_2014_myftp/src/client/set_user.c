/*
** set_user.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Mar 24 22:57:30 2015 Pierrick Gicquelais
** Last update Wed Mar 25 15:00:25 2015 Pierrick Gicquelais
*/

#include	"set_user.h"
#include	"split_string.h"
#include	"swrite.h"

void		set_user(t_client *cli, char *cmd)
{
  char		*username;

  if (cli->login == false)
    {
      username = split_string(cmd, ' ', 1);
      if (username != NULL)
	cli->username = strdup(username);
    }
}
