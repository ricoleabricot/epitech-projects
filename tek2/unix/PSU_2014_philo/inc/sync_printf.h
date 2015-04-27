/*
** sync_printf.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_philo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 18:38:51 2015 Pierrick Gicquelais
** Last update Sat Feb 28 02:12:22 2015 Antoine Plaskowski
*/

#ifndef		SYNC_PRINTF_H_
# define	SYNC_PRINTF_H_

# include	<stdbool.h>
# include	<stdarg.h>

extern bool	g_verbose;

int		sync_printf(const char *format, ...);

#endif		/* !SYNC_PRINTF_H_ */
