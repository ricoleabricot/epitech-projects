/*
** file_complements.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 18:41:37 2015 Pierrick Gicquelais
** Last update Sun Apr 12 19:12:12 2015 Pierrick Gicquelais
*/

#include	"file.h"

t_file		*get_file_by_fromto(t_file *files, char *from, char *to)
{
  files = first_file(files);
  while (files != NULL)
    {
      if (strcmp(files->from, from) == 0 && strcmp(files->to, to) == 0)
	return (files);
      files = files->next;
    }
  return (NULL);
}

t_file		*get_file_by_fd(t_file *files, int fd)
{
  files = first_file(files);
  while (files != NULL)
    {
      if (files->fd == fd)
	return (files);
      files = files->next;
    }
  return (NULL);
}
