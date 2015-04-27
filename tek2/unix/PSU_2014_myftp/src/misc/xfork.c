/*
** xfork.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 17:36:22 2015 Pierrick Gicquelais
** Last update Fri Mar 13 17:37:29 2015 Pierrick Gicquelais
*/

#include	"xfork.h"
#include	"merror.h"

pid_t		xfork(int sockfd)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    {
      close(sockfd);
      merror("Fork error");
    }
  return (pid);
}
