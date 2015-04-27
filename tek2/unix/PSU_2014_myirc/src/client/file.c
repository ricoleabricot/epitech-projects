/*
** file.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 12:11:09 2015 Pierrick Gicquelais
** Last update Wed Apr 15 15:42:58 2015 Pierrick Gicquelais
*/

#include	"file_client.h"
#include	"split_string.h"
#include	"swrite.h"

void		send_file(t_client *cli, char *ret)
{
  char		*filename;
  char		buf[512];
  int		fd;
  int		r;

  filename = split_string(ret, ':', 1);
  if (filename != NULL)
    {
      if ((fd = open(filename, O_RDONLY)) != -1)
	{
	  while ((r = read(fd, buf, 511)) > 0)
	    {
	      buf[r] = 0;
	      write(cli->sf, buf, strlen(buf));
	    }
	  close(fd);
	}
      free(filename);
    }
  close(cli->sf);
}

void	        receive_file(t_client *cli)
{
  (void)cli;
}
