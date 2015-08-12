/*
** xlisten.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:18:45 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:55:44 2015 Pierrick Gicquelais
*/

#include	"server/xlisten.h"

int		xlisten(int sockfd, int backlog)
{
  int		ret;

  if ((ret = listen(sockfd, backlog)) == -1)
    merror("Listen Error");
  return (ret);
}
