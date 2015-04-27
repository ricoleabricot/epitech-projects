/*
** xgetprotobyname.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/misc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 13:00:36 2015 Pierrick Gicquelais
** Last update Sat Apr  4 13:00:37 2015 Pierrick Gicquelais
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
