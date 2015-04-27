/*
** algo_philo.c for algo_philo in /home/plasko_a/projet/epitech/PSU_2014_philo
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 24 21:03:21 2015 Antoine Plaskowski
** Last update Wed Feb 25 11:53:19 2015 Pierrick Gicquelais
*/

#include	<stdbool.h>
#include	"algo_philo.h"
#include	"philo.h"

bool		algo_philo_init(t_philo *philos, size_t n)
{
  size_t	i;

  if (philos == NULL || n <= 1)
    return (false);
  if (pthread_mutex_trylock(philos->left_my) != 0 ||
      pthread_mutex_unlock(philos->left_my) != 0 ||
      pthread_mutex_trylock(philos->right_my) != 0||
      pthread_mutex_unlock(philos->right_my) != 0)
    return (false);
  i = 1;
  while (i < n - 1)
    {
      if (pthread_mutex_trylock(philos[i].left_my) != 0 ||
	  pthread_mutex_trylock(philos[i].right_my) != 0||
	  pthread_mutex_unlock(philos[i].right_my) != 0)
	return (false);
      i++;
    }
  if (pthread_mutex_trylock(philos[i].left_my) != 0 ||
      pthread_mutex_trylock(philos[i].right_my) != 0)
    return (false);
  return (true);
}
