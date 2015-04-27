/*
** read_client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 17:09:28 2015 Pierrick Gicquelais
** Last update Sun Apr 12 12:06:46 2015 Pierrick Gicquelais
*/

#ifndef		READ_CLIENT_H_
# define	READ_CLIENT_H_

# include	"client.h"

bool		read_on_input(t_client *);
bool		read_on_socket(t_client *);

#endif		/* !READ_CLIENT_H_ */
