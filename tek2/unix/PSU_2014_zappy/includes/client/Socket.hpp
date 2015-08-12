//
// Socket.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun 15 22:23:51 2015 rousse_3
// Last update Thu Jun 25 15:50:24 2015 rousse_3
//

#ifndef			SOCKET_HPP_
# define		SOCKET_HPP_

# include		<string>
# include		<netdb.h>

class			Socket
{
public:
  Socket(const std::string &ip, int port);
  ~Socket(void);

  bool			readLine(std::string &buffer);
  int			sendData(const std::string &str) const;
  bool			wait(int time);
private:
  int			_fd;
  struct sockaddr_in	*_info;
  std::string		_buff;
};

#endif			/* !SOCKET_HPP_ */
