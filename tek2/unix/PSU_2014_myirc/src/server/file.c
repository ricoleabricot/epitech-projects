/*
** file.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 12:18:25 2015 Pierrick Gicquelais
** Last update Sun Apr 12 19:16:31 2015 Pierrick Gicquelais
*/

#include	"file.h"
#include	"split_string.h"
#include	"xmalloc.h"

t_file		*new_file(void)
{
  t_file	*file;

  file = xmalloc(sizeof(t_file));

  file->prev = NULL;
  file->next = NULL;

  file->from = NULL;
  file->to = NULL;
  file->name = NULL;

  file->fd = 0;

  return (file);
}

t_file		*append_file(t_file *old, char *name, int fd)
{
  t_file	*new;

  new = new_file();

  if ((old = last_file(old)) != NULL)
    old->next = new;

  new->from = split_string(name, '_', 0);
  new->to = split_string(name, '_', 1);
  new->name = strdup(name);
  new->fd = fd;

  new->prev = old;
  new->next = NULL;

  return (new);
}

void		free_file(t_file *file)
{
  if (file != NULL)
    {
      if (file->from != NULL)
	free(file->from);
      if (file->to != NULL)
	free(file->to);
      if (file->name != NULL)
	free(file->name);
      free(file);
    }
}

void		free_files(t_file *files)
{
  t_file	*tmp;

  files = first_file(files);
  while (files != NULL)
    {
      tmp = files;
      files = files->next;
      free_file(tmp);
    }
}

bool		file_exists(t_file *files, char *name)
{
  files = first_file(files);
  while (files != NULL)
    {
      if (strcmp(files->name, name) == 0)
	return (true);
      files = files->next;
    }
  return (false);
}
