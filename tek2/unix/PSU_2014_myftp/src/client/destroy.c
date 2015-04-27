/*
** destroy.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:14:05 2015 Pierrick Gicquelais
** Last update Fri Mar 27 17:34:21 2015 Pierrick Gicquelais
*/

#include	"destroy_client.h"

void		destroy(t_client *cli)
{
  close(cli->fd);
  free(cli->data);
  free(cli);
  exit(EXIT_SUCCESS);
}
