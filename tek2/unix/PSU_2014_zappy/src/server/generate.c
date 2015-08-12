/*
** generate.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jun 23 14:46:19 2015 Pierrick Gicquelais
** Last update Tue Jun 23 16:56:19 2015 Christian Boisson
*/

#include	<stdlib.h>
#include	<time.h>
#include	"server/generate.h"

void		generate(t_server *server)
{
  srand(time(NULL));
  generate_resources(server->map);
}
