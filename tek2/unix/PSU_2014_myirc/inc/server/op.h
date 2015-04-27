/*
** op.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Apr  8 17:29:12 2015 Pierrick Gicquelais
** Last update Thu Apr  9 13:38:06 2015 Pierrick Gicquelais
*/

#ifndef		OP_H_
# define	OP_H_

# include	"server.h"

t_op		*new_op(void);
t_op		*append_op(t_op *, char *);
t_op		*first_op(t_op *);
t_op		*last_op(t_op *);
t_op		*pop_op(t_op *, char *);

bool		op_exists(t_op *, char *);

void		aff_ops(t_op *, t_user *, int);
void		free_op(t_op *);
void		free_ops(t_op *);

#endif		/* !OP_H_ */
