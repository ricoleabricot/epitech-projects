/*
** commands.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Apr  4 17:09:42 2015 Pierrick Gicquelais
** Last update Thu Apr 16 12:56:54 2015 Pierrick Gicquelais
*/

#ifndef		COMMANDS_H_
# define	COMMANDS_H_

# include	"server.h"

# define	SERVER	("SERVER")
# define	NICK	("NICK")
# define	LIST	("LIST")
# define	JOIN	("JOIN")
# define	PART	("PART")
# define	USERS	("USERS")
# define	PRIVMSG	("PRIVMSG")
# define	MSG	("MSG")
# define	SEND	("SEND_FILE")
# define	ACCEPT	("ACCEPT_FILE")

# define	NAMES	("NAMES")
# define	OPER	("OPER")
# define	DEOPER	("DEOPER")
# define	KICK	("KICK")
# define	KILL	("KILL")
# define	CREATE	("CREATE")
# define	INVITE	("INVITE")
# define	MODE	("MODE")
# define	PASS	("PASS")
# define	USER	("USER")
# define	ME	("ME")
# define	TOPIC	("TOPIC")
# define	HELP	("HELP")
# define	QUIT	("QUIT")

# define	PUBLIC	("0")
# define	PRIVATE	("1")

void		commands(t_server *, t_user *, char *);

void	        server(t_server *, t_user *, char *);
void	        nick(t_server *, t_user *, char *);
void	        list(t_server *, t_user *, char *);
void	        join(t_server *, t_user *, char *);
void	        part(t_server *, t_user *, char *);
void	        users(t_server *, t_user *, char *);
void	        msg(t_server *, t_user *, char *);
void	        send_file(t_server *, t_user *, char *);
void		accept_file(t_server *, t_user *, char *);

void		names(t_server *, t_user *, char *);
void		op(t_server *, t_user *, char *);
void		deop(t_server *, t_user *, char *);
void		kick(t_server *, t_user *, char *);
void		kill(t_server *, t_user *, char *);
void	        create(t_server *, t_user *, char *);
void		invite(t_server *, t_user *, char *);
void		mode(t_server *, t_user *, char *);
void		pass(t_server *, t_user *, char *);
void		user(t_server *, t_user *, char *);
void	        me(t_server *, t_user *, char *);
void		topic(t_server *, t_user *, char *);
void		help(t_server *, t_user *, char *);
void		quit(t_server *, t_user *, char *);

#endif		/* !COMMANDS_H_ */
