/*
** channel_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:04:07 2015 Pierrick Gicquelais
** Last update Fri Apr 10 18:05:14 2015 Pierrick Gicquelais
*/

#include	"channel.h"

t_channel	*get_channel_by_name(t_channel *ch, char *name)
{
  ch = first_channel(ch);
  while (ch != NULL)
    {
      if (strcmp(ch->name, name) == 0)
	return (ch);
      ch = ch->next;
    }
  return (NULL);
}

bool		channel_exists(t_channel *chs, char *name)
{
  chs = first_channel(chs);
  while (chs != NULL)
    {
      if (strcmp(chs->name, name) == 0)
	return (true);
      chs = chs->next;
    }
  return (false);
}

bool		is_invite(t_channel *ch, char *nick)
{
  if (ch->toinvite && strcmp(ch->toinvite, nick) == 0)
    return (true);
  return (false);
}
