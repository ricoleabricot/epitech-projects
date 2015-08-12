/*
** xgetprotobyname.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 17:25:01 2015 Pierrick Gicquelais
** Last update Thu Jun 18 17:55:52 2015 Pierrick Gicquelais
*/

#include	"server/xgetprotobyname.h"

struct protoent	*xgetprotobyname(const char *name)
{
  struct protoent	*ret;

  if ((ret = getprotobyname(name)) == NULL)
    merror("Getprotobyname Error");
  return (ret);
}
