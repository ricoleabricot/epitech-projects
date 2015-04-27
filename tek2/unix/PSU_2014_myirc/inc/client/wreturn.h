/*
** wreturn.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 18:09:16 2015 Pierrick Gicquelais
** Last update Wed Apr 15 22:13:24 2015 Pierrick Gicquelais
*/

#ifndef		WRETURN_H_
# define	WRETURN_H_

# include	"client.h"

# define	NICK	("NICK")
# define	JOIN	("JOIN")
# define	PART	("PART")
# define	SEND	("SEND_FILE")
# define	ACCEPT	("ACCEPT_FILE")

void		rreturn(t_client *);
void		freturn(char *);
void		wreturn(t_client *, char *);

#endif		/* !WRETURN_H_ */
