/*
** xlisten.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:33:55 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:50:36 2015 Pierrick Gicquelais
*/

#include	"xlisten.h"
#include	"merror.h"

int		xlisten(int sockfd, int backlog)
{
  int		ret;

  if ((ret = listen(sockfd, backlog)) == -1)
    {
      close(sockfd);
      merror("Listen Error");
    }
  return (ret);
}

