/*
** run.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:39:47 2015 Pierrick Gicquelais
** Last update Fri Mar 27 15:24:47 2015 Pierrick Gicquelais
*/

#include	"run_server.h"
#include	"do_actions_server.h"
#include	"actions.h"
#include	"destroy_server.h"
#include	"xaccept.h"
#include	"xfork.h"
#include	"swrite.h"

t_server	*g_server;

static void	sig_handler(int sig)
{
  (void)sig;
  quit(g_server, NULL);
  write(1, "\nBye.\n", strlen("\nBye.\n"));
  destroy(g_server);
  exit(EXIT_SUCCESS);
}

void		run(t_server *serv)
{
  pid_t		pid;
  char		buf[4096];

  while (true)
    {
      g_server = serv;
      signal(SIGINT, sig_handler);
      signal(SIGPIPE, sig_handler);
      serv->cfd = xaccept(serv->fd, \
			  (struct sockaddr *)&serv->csin, &serv->len);
      pid = xfork(serv->fd);
      if (pid == 0)
  	{
	  printf("Connection from: %s:%d\n", inet_ntoa(serv->csin.sin_addr), \
		 ntohs(serv->csin.sin_port));
	  swrite(serv->cfd, "220 Kafei myFTP server (Ubuntu 14.01 LTS)\r\n");
	  while (memset(buf, 0, 4096) && read(serv->cfd, buf, 4096) > 0)
	    do_actions(serv, buf);
	  printf("Disconnection from: %s:%d\n", \
		 inet_ntoa(serv->csin.sin_addr), ntohs(serv->csin.sin_port));
	  close(serv->cfd);
	  exit(EXIT_SUCCESS);
	}
    }
}
