/*
** is_reply.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr 11 21:34:40 2015 Pierrick Gicquelais
** Last update Wed Apr 15 12:02:44 2015 Pierrick Gicquelais
*/

#ifndef		IS_REPLY_H_
# define	IS_REPLY_H_

# include	<stdlib.h>
# include	<string.h>
# include	<ctype.h>
# include	<stdbool.h>

# define	NICK	("NICK")
# define	JOIN	("JOIN")
# define	PART	("PART")
# define	SEND	("SEND_FILE")
# define	ACCEPT	("ACCEPT_FILE")

bool		is_reply(char *);

#endif		/* !IS_REPLY_H_ */
