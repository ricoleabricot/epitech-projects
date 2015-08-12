/*
** write.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Jun 28 12:47:10 2015 Pierrick Gicquelais
** Last update Sun Jul  5 21:07:19 2015 Pierrick Gicquelais
*/

#ifndef		WRITE_H_
# define	WRITE_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>

# include	"verbose.h"
# include	"commands_graphic.h"
# include	"swrite.h"

t_client	*client_write(t_server *, t_client *, bool);

#endif		/* !WRITE_H_ */
