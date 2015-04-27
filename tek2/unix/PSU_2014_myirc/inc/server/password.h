/*
** password.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Apr 10 18:33:39 2015 Pierrick Gicquelais
** Last update Fri Apr 10 18:34:21 2015 Pierrick Gicquelais
*/

#ifndef		PASSWORD_H_
# define	PASSWORD_H_

# include	"server.h"

bool		password_exists(char *, int);
bool		password_correct(char *, char *, int);

#endif		/* !PASSWORD_H_ */
