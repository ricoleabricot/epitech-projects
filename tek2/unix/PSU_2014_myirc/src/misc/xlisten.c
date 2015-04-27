/*
** xlisten.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:41 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:41 2015 Pierrick Gicquelais
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

