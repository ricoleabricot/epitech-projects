/*
** dinner_philo.c for dinner_philo in /home/plasko_a/projet/epitech/PSU_2014_philo
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 24 23:17:58 2015 Antoine Plaskowski
** Last update Sun Mar  1 22:59:18 2015 Antoine Plaskowski
*/

/*
**	usleep
*/

#define		_DEFAULT_SOURCE
#define		_BSD_SOURCE
#include	<unistd.h>
#undef		_DEFAULT_SOURCE

#include	<stdarg.h>
#include	<stdbool.h>
#include	<stdio.h>
#include	"philo.h"
#include	"dinner_philo.h"
#include	"sync_printf.h"

static pthread_mutex_t	g_m_rice = PTHREAD_MUTEX_INITIALIZER;
size_t			g_rice = 42 * 7;

static size_t	read_rice(void)
{
  size_t	ret;

  pthread_mutex_lock(&g_m_rice);
  ret = g_rice;
  pthread_mutex_unlock(&g_m_rice);
  return (ret);
}

static bool	eat_philo(t_philo *philo)
{
  bool		ret;

  pthread_mutex_lock(&g_m_rice);
  if (g_rice == 0)
    ret = false;
  else
    {
      sync_printf("Je mange et je suis le philosophe n°%lu\n", philo->id);
      ret = true;
      philo->rice++;
      g_rice--;
    }
  pthread_mutex_unlock(&g_m_rice);
  return (ret);
}

static void	unlock_philo(t_philo *philo, int left, int right)
{
  if (left == 0)
    pthread_mutex_unlock(philo->left_other);
  if (right == 0)
    pthread_mutex_unlock(philo->right_other);
}

static void	medite_philo(t_philo *philo, int *left, int *right)
{
  sync_printf("Je médite et je suis le philosophe n°%lu\n", philo->id);
  if (*left == 0)
    while (*right != 0 && read_rice() != 0)
      {
	usleep(5);
	philo->medite++;
	*right = pthread_mutex_trylock(philo->right_my);
      }
  else
    while (*left != 0 && read_rice() != 0)
      {
	usleep(5);
	philo->medite++;
	*left = pthread_mutex_trylock(philo->left_my);
      }
}

void		*dinner_philo(t_philo *philo)
{
  int		left;
  int		right;

  while (read_rice() != 0)
    {
      left = pthread_mutex_trylock(philo->left_my);
      right = pthread_mutex_trylock(philo->right_my);
      if (left == 0 && right == 0)
	eat_philo(philo);
      else if (left != 0 && right != 0)
	{
	  usleep(10);
	  sync_printf("Je me repose et je suis le philosophe n°%lu\n",
		      philo->id);
	  philo->repos++;
	}
      else
	{
	  medite_philo(philo, &left, &right);
	  eat_philo(philo);
	}
      unlock_philo(philo, left, right);
    }
  return (NULL);
}
