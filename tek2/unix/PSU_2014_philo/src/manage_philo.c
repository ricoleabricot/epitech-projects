/*
** manage_philo.c for manage_philo in /home/plasko_a/projet/epitech/PSU_2014_philo
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 24 22:01:18 2015 Antoine Plaskowski
** Last update Fri Feb 27 18:31:32 2015 Pierrick Gicquelais
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"manage_philo.h"
#include	"philo.h"
#include	"dinner_philo.h"

static pthread_t	*alloc_pthreads(t_philo *philos, size_t n)
{
  pthread_t		*pthreads;
  size_t		i;

  if ((pthreads = malloc(sizeof(*pthreads) * n)) == NULL)
    return (false);
  i = 0;
  while (i < n)
    {
      if (pthread_create(pthreads + i, NULL,
			 (void *(*)(void *))dinner_philo, philos + i))
	return (false);
      i++;
    }
  return (pthreads);
}

static bool	join_pthreads(pthread_t *pthreads, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    {
      if (pthread_join(pthreads[i], NULL))
	return (false);
      i++;
    }
  return (true);
}

bool		manage_philos(t_philo *philos, size_t n)
{
  pthread_t	*pthreads;

  if (philos == NULL)
    return (false);
  if ((pthreads = alloc_pthreads(philos, n)) == NULL)
    return (false);
  if (join_pthreads(pthreads, n) == false)
    return (false);
  free(pthreads);
  return (true);
}
