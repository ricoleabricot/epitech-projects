/*
** opt.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 17:43:19 2015 Pierrick Gicquelais
** Last update Fri Feb 27 18:00:53 2015 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdbool.h>

#include	"opt.h"

char		*opt_search(char **argv, char const *str)
{
  size_t          len;

  if (str == NULL)
    return (NULL);
  len = strlen(str);
  while (*argv != NULL)
    {
      if (strncasecmp(*argv, str, len) == 0)
	return (*argv + len);
      argv++;
    }
  return (NULL);
}

size_t		opt_n_philo(char **argv)
{
  char		*opt;

  if ((opt = opt_search(argv, "--size=")) != NULL)
    return (strtoul(opt, NULL, 10));
  return (7);
}

size_t		opt_rice_philo(char **argv)
{
  char		*opt;

  if ((opt = opt_search(argv, "--rice=")) != NULL)
    return (strtoul(opt, NULL, 10));
  return (42 * 7);
}

bool		opt_verbose_philo(char **argv)
{
  char		*opt;

  if ((opt = opt_search(argv, "--verbose")) != NULL)
    return (true);
  return (false);
}

bool		opt_help(char **argv)
{
  bool const	ret = opt_search(argv, "--help") != NULL;

  if (ret == true)
    {
      fprintf(stderr, "./philo --help\n");
      fprintf(stderr, "./philo --size=?(7)\n");
      fprintf(stderr, "./philo --rice=?(42 * 7)\n");
      fprintf(stderr, "./philo --verbose\n");
    }
  return (ret);
}
