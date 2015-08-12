//
// Socket.hh for zappy in /home/ribeir_b/rendu/PSU_2014_zappy/graphique
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jun 24 14:49:34 2015 Nicolas Ribeiro Teixeira
// Last update Wed Jun 24 17:14:04 2015 Nicolas Ribeiro Teixeira
//

#ifndef		SOCKET_HH_
# define	SOCKET_HH_

# include	<poll.h>
# include	<string>

class		Socket
{
private:
  bool		m_okay;
  int		m_sock;
  struct pollfd	m_fds;
public:
  Socket(std::string const &serv, int port);
  ~Socket();
  bool		getOkay(void) const;
  bool		toRead(void);
  int		sendMessage(std::string const &msg);
  std::string	receiveMessage(void);
};

#endif		/* !SOCKET_HH_ */
