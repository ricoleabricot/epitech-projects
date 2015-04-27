/*
** destroy.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:42:32 2015 Pierrick Gicquelais
** Last update Fri Mar 27 13:55:43 2015 Pierrick Gicquelais
*/

#include	"destroy_server.h"
#include	"swrite.h"

void		destroy_data(t_data *data)
{
  swrite(data->cfd, "226 Closing data connection\r\n");
  close(data->cfd);
  close(data->fd);
}

void		destroy(t_server *serv)
{
  if (serv->root != NULL)
    free(serv->root);
  if (serv->save_file != NULL)
    free(serv->save_file);
  if (serv->username != NULL)
    free(serv->username);
  close(serv->cfd);
  close(serv->fd);
  free(serv->data);
  free(serv);
}
