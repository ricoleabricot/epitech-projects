/*
** ia.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Mar  8 19:29:55 2015 Pierrick Gicquelais
** Last update Sun Mar 08 19:36:55 2015 Cyril Labitte
*/

#ifndef		IA_H
# define	IA_H

# include	<sys/types.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>
# include	<sys/sem.h>
# include	<sys/msg.h>
# include	<strings.h>
# include	<stdlib.h>

# include	"lemipc.h"
# include	"xmalloc.h"
# include	"error.h"
# include	"xmsg.h"
# include	"move.h"



int	get_end(int a);
int	find_enemy(t_ipc *ipc);
int	send_id(t_ipc *ipc, int *en_pos, int *msg_id, t_msg *message);
int	ia(t_ipc *ipc);

#endif		/* IA_H */
