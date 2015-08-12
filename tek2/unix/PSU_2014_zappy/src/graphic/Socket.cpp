//
// Socket.cpp for zappy in /home/ribeir_b/rendu/PSU_2014_zappy/graphique
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jun 24 14:52:58 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 21:33:00 2015 Nicolas Ribeiro Teixeira
//

#include	<arpa/inet.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<poll.h>
#include	<iostream>
#include	"graphic/Socket.hh"

Socket::Socket(std::string const &serv, int port)
{
  struct protoent	*pe;
  struct sockaddr_in	sockaddr;
  socklen_t		socksize;
  int			sock;
  int			okay;

  pe = getprotobyname("TCP");
  socksize = sizeof(struct sockaddr);
  if ((sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      std::cerr << "Socket creation failed." << std::endl;
      exit(2);
    }
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(port);
  sockaddr.sin_addr.s_addr = inet_addr(serv.c_str());
  if ((connect(sock, reinterpret_cast<const struct sockaddr *>(&sockaddr), socksize)) != 0)
    {
      std::cerr << "Socket connection failed." << std::endl;
      exit(3);
    }
  m_sock = sock;
  m_fds.fd = m_sock;
  m_fds.events = POLLIN;
  okay = 0;
  if (toRead())
    {
      okay = 1;
      if (receiveMessage() != "BIENVENUE")
	okay = 0;
    }
  if (okay)
    {
      m_okay = true;
      sendMessage("GRAPHIC");
    }
  else
    {
      m_okay = false;
      std::cerr << "\'BIENVENUE\' not received..." << std::endl << "Exiting ..." << std::endl;
    }
}

Socket::~Socket()
{
}

bool		Socket::getOkay(void) const
{
  if (m_okay)
    return (true);
  return (false);
}

bool		Socket::toRead(void)
{
  int		ret;

  m_fds.fd = m_sock;
  m_fds.events = POLLIN;
  ret = poll(&m_fds, 1, 5);
  if (ret && (m_fds.revents & POLLIN))
    return (true);
  return (false);
}

int		Socket::sendMessage(std::string const &msg)
{
  std::string	full_msg(msg + "\n");

  return (write(m_sock, full_msg.c_str(), full_msg.length()));
}

std::string	Socket::receiveMessage(void)
{
  std::string	msg("");
  std::string	buf(2, 0);
  int		readret;

  while ((readret = (read(m_sock, &buf[0], 1))) > 0 && buf[0] != '\n')
    {
      if (buf[0] != '\n')
	msg = msg + buf[0];
    }
  if (readret == 0)
    {
      std::cerr << "EOF catched on the server..." << std::endl << "Exiting ..." << std::endl;
      exit (-1);
    }
  return (msg);
}
