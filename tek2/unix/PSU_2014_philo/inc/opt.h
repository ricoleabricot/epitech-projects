/*
** opt.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 17:49:17 2015 Pierrick Gicquelais
** Last update Fri Feb 27 17:59:00 2015 Pierrick Gicquelais
*/

#ifndef		OPT_H_
# define	OPT_H_

char		*opt_search(char **, char const *);
size_t		opt_n_philo(char **);
size_t		opt_rice_philo(char **);
bool		opt_verbose_philo(char **argv);
bool		opt_help(char **);

#endif		/* !OPT_H_ */
