/*
** test.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo/src
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Feb 24 20:05:18 2015 Pierrick Gicquelais
** Last update Thu Feb 26 12:08:57 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	"philo.h"
#include	"test.h"

bool		test_philos(t_philo *philos, size_t n)
{
  size_t	i;

  if (philos == NULL)
    return (false);
  printf("--------------\n");
  i = 0;
  while (i < n)
    {
      printf("id: %lu\n", philos[i].id);
      printf("rice: %lu\n", philos[i].rice);
      printf("left_my: %p\n", (void *)philos[i].left_my);
      printf("left_other: %p\n",  (void *)philos[i].left_other);
      printf("right_my: %p\n",  (void *)philos[i].right_my);
      printf("right_other: %p\n",  (void *)philos[i].right_other);
      printf("--------------\n");
      i++;
    }
  return (true);
}
