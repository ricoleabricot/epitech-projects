/*
** is_error.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 20:14:40 2015 Pierrick Gicquelais
** Last update Sun Apr 12 20:15:24 2015 Pierrick Gicquelais
*/

#include	"is_error.h"

bool		is_error(char *str)
{
  if (strlen(str) > 8)
    {
      if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && \
	  str[4] == 'E' && str[5] == 'R' && str[6] == 'R')
	return (true);
    }
  return (false);
}
