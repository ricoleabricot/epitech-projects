/*
** dinner_philo.h for dinner_philo in /home/plasko_a/projet/epitech/PSU_2014_philo
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 24 23:17:46 2015 Antoine Plaskowski
** Last update Sat Feb 28 02:07:54 2015 Antoine Plaskowski
*/

#ifndef		DINNER_PHILO_H_
# define	DINNER_PHILO_H_

# include	<stdbool.h>
# include	"philo.h"

extern size_t	g_rice;

void		*dinner_philo(t_philo *philo);
bool		is_checking_chop(t_philo *, int, int);
bool		is_meditating(t_philo *, int *, int *);
bool		is_eating(t_philo *);
bool		is_initializing(t_philo *, int *, int *);

#endif		/* !DINNER_PHILO_H_ */
