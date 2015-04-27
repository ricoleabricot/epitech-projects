/*
** sync_printf.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 18:38:36 2015 Pierrick Gicquelais
** Last update Sat Feb 28 02:14:28 2015 Antoine Plaskowski
*/

#include	<pthread.h>
#include	<stdio.h>
#include	"sync_printf.h"

bool		g_verbose = false;

int				sync_printf(char const *format, ...)
{
  static pthread_mutex_t	m_printf = PTHREAD_MUTEX_INITIALIZER;
  va_list			ap;
  int				ret;

  if (g_verbose == true)
    {
      va_start(ap, format);
      pthread_mutex_lock(&m_printf);
      ret = vprintf(format, ap);
      pthread_mutex_unlock(&m_printf);
      va_end(ap);
    }
  else
    ret = 0;
  return (ret);
}
