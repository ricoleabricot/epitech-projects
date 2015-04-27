/*
** xgetprotobyname.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar 13 11:34:08 2015 Pierrick Gicquelais
** Last update Fri Mar 13 11:49:45 2015 Pierrick Gicquelais
*/

#include		"xgetprotobyname.h"
#include		"merror.h"

struct protoent		*xgetprotobyname(const char *name)
{
  struct protoent	*ent;

  if ((ent = getprotobyname(name)) == NULL)
    merror("Getprotobyname Error");
  return (ent);
}
