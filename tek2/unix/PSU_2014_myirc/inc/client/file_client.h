/*
** file_client.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 17:58:29 2015 Pierrick Gicquelais
** Last update Sun Apr 12 22:52:21 2015 Pierrick Gicquelais
*/

#ifndef		FILE_CLIENT_H_
# define	FILE_CLIENT_H_

# include	"client.h"

void		send_file(t_client *, char *);
void		receive_file(t_client *);

#endif		/* !FILE_CLIENT_H_ */
