/*
** channel.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:21:08 2015 Pierrick Gicquelais
** Last update Wed Apr 15 09:36:02 2015 Pierrick Gicquelais
*/

#include	"channel.h"
#include	"op.h"
#include	"xmalloc.h"
#include	"swrite.h"

t_channel	*new_channel(void)
{
  t_channel	*ch;

  ch = xmalloc(sizeof(t_channel));

  ch->prev = NULL;
  ch->next = NULL;

  ch->name = NULL;
  ch->topic = NULL;
  ch->ops = NULL;

  ch->toinvite = NULL;
  ch->private = false;

  return (ch);
}

t_channel	*append_channel(t_channel *old, char *name)
{
  t_channel	*new;

  new = new_channel();

  if ((old = last_channel(old)) != NULL)
    old->next = new;

  new->name = strdup(name);
  new->prev = old;
  new->next = NULL;

  return (new);
}

void		aff_channels(t_channel *ch, char *name, int fd)
{
  char		ret[512];

  ch = first_channel(ch);
  while (ch != NULL)
    {
      if (name == NULL || strcasestr(ch->name, name))
	{
	  if (ch->private)
	    sprintf(ret, "322 RPL_LIST :~%s", ch->name);
	  else
	    sprintf(ret, "322 RPL_LIST :%s", ch->name);

	  if (ch->topic != NULL)
	    sprintf(ret, "%s :%s\r\n", ret, ch->topic);
	  else
	    sprintf(ret, "%s :No topic\r\n", ret);

	  swrite(fd, ret);
	}
      ch = ch->next;
    }
}

void		free_channel(t_channel *ch)
{
  if (ch != NULL)
    {
      if (ch->name != NULL)
	free(ch->name);
      if (ch->toinvite != NULL)
	free(ch->toinvite);
      free_ops(ch->ops);
      free(ch);
    }
}

void		free_channels(t_channel *chs)
{
  t_channel	*tmp;

  chs = first_channel(chs);
  while (chs != NULL)
    {
      tmp = chs;
      chs = chs->next;
      free_channel(tmp);
    }
}
