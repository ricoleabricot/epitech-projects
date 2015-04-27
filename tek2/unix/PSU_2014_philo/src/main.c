/*
** main.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 24 18:07:39 2015 Pierrick Gicquelais
** Last update Sat Feb 28 02:10:06 2015 Antoine Plaskowski
*/

#include	<pthread.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"philo.h"
#include	"test.h"
#include	"algo_philo.h"
#include	"manage_philo.h"
#include	"dinner_philo.h"
#include	"opt.h"
#include	"sync_printf.h"

int		main(int argc, char **argv)
{
  t_philo	*philos;
  size_t const	n = opt_n_philo(argv);

  (void)argc;
  if (opt_help(argv) == true)
    return (0);
  if (n <= 1)
    fprintf(stderr, "You need more philosopher !\n");
  g_verbose = opt_verbose_philo(argv);
  g_rice = opt_rice_philo(argv);
  philos = philos_create(n);
  algo_philo_init(philos, n);
  manage_philos(philos, n);
  philos_free(philos, n);
  return (0);
}
