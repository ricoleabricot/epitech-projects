/*
** philo.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo/inc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 24 18:09:49 2015 Pierrick Gicquelais
** Last update Sun Mar  1 21:04:04 2015 Antoine Plaskowski
*/

#ifndef			PHILO_H_
# define		PHILO_H_

# include		<pthread.h>
# include		<stddef.h>

typedef struct		s_philo t_philo;

struct			s_philo
{
  size_t		id;
  size_t		rice;
  size_t		medite;
  size_t		repos;
  pthread_mutex_t	*left_my;
  pthread_mutex_t	*left_other;
  pthread_mutex_t	*right_my;
  pthread_mutex_t	*right_other;
};

void			philo_free(t_philo *philo);
void			philos_free(t_philo *philos, size_t n);

t_philo			*philo_init(t_philo *philo);
t_philo			*philos_create(size_t n);

#endif			/* !PHILO_H_ */

