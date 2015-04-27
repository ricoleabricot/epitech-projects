/*
** philo.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 24 18:13:05 2015 Pierrick Gicquelais
** Last update Sun Mar  1 21:04:40 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stddef.h>

#include	"philo.h"
#include	"sync_printf.h"

void		philo_free(t_philo *philo)
{
  if (philo != NULL)
    {
      printf("Je suis %lu et j'ai mangé %lu bol(s) de riz !\n",
	     philo->id, philo->rice);
      printf("J'ai medité %lu et je me suis reposé %lu\n",
	     philo->medite, philo->repos);
      free(philo->left_my);
      free(philo->right_my);
      free(philo);
    }
}

void		philos_free(t_philo *philos, size_t n)
{
  size_t	i;

  if (philos != NULL)
    {
      i = 0;
      while (i < n)
	{
	  free(philos[i].left_my);
	  free(philos[i].right_my);
	  printf("Je suis %lu et j'ai mangé %lu bol(s) de riz *yum*\n",
		 philos[i].id, philos[i].rice);
	  printf("J'ai medité %lu et je me suis reposé %lu\n",
		 philos[i].medite, philos[i].repos);
	  i++;
	}
      free(philos);
    }
}

t_philo		*philo_init(t_philo *philo)
{
  if (philo == NULL)
    return (NULL);
  if ((philo->left_my = malloc(sizeof(*philo->left_my))) == NULL)
    return (NULL);
  if (pthread_mutex_init(philo->left_my, NULL) != 0)
    return (NULL);
  if ((philo->right_my = malloc(sizeof(*philo->right_my))) == NULL)
    return (NULL);
  if (pthread_mutex_init(philo->right_my, NULL) != 0)
    return (NULL);
  philo->id = 0;
  philo->rice = 0;
  philo->medite = 0;
  philo->repos = 0;
  return (philo);
}

static void	philos_link(t_philo *philos, size_t n)
{
  size_t	i;

  philos->left_other = philos[n - 1].right_my;
  philos->right_other = philos[1].left_my;
  i = 1;
  while (i < n - 1)
    {
      philos[i].left_other = philos[i - 1].right_my;
      philos[i].right_other = philos[i + 1].left_my;
      i++;
    }
  philos[i].left_other = philos[i - 1].right_my;
  philos[i].right_other = philos->left_my;
}

t_philo		*philos_create(size_t n)
{
  t_philo	*philos;
  size_t	i;

  if (n <= 1)
    return (NULL);
  if ((philos = malloc(sizeof(*philos) * n)) == NULL)
    return (NULL);
  i = 0;
  while (i < n)
    {
      if (philo_init(philos + i) == NULL)
	{
	  philos_free(philos, i);
	  free(philos);
	  return (NULL);
	}
      philos[i].id = i;
      i++;
    }
  philos_link(philos, n);
  return (philos);
}
