//
// Socket.cpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun 15 22:34:19 2015 rousse_3
// Last update Mon Jun 29 18:06:36 2015 rousse_3
//

#include	<unistd.h>
#include	<sys/select.h>
#include	<arpa/inet.h>
#include	"client/Error.hpp"
#include	"client/Socket.hpp"

Socket::Socket(const std::string &ip, int port) : _fd(-1), _info(NULL), _buff()
{
  _info = new struct sockaddr_in;
  _info->sin_family = AF_INET;
  _info->sin_port = htons(port);
  _info->sin_addr.s_addr = inet_addr(ip.c_str());
  _fd = socket(AF_INET, SOCK_STREAM, 0);
  if ((connect(_fd, (sockaddr*)_info, sizeof(*_info))) != 0)
    throw ConnectionError("Cannot connect with the server");
}

Socket::~Socket(void)
{
  if (_info != NULL)
    delete _info;
}

bool			Socket::readLine(std::string &buffer)
{
  char			tmp[256];
  int			size = 1;
  bool			ret = false;

  while (wait(10) && size > 0 && _buff.find("\n") == std::string::npos)
    {
      size = read(_fd, tmp, 255);
      tmp[size] = '\0';
      _buff += tmp;
      if (size == 0)
	throw ConnectionError("Cannot read on the server");
    }
  if (_buff.find("\n") != std::string::npos)
    {
      buffer = _buff.substr(0, _buff.find("\n"));
      _buff = _buff.substr(_buff.find("\n") + 1);
      ret = true;
    }
  return (ret);
}

int			Socket::sendData(const std::string &str) const
{
  return (write(_fd, str.c_str(), str.size()));
}

bool			Socket::wait(int wait)
{
  struct timeval	time;
  fd_set		fdRead;
  int			ret;

  FD_ZERO(&fdRead);
  FD_SET(_fd, &fdRead);
  if (wait == -1)
    {
      if ((ret = select(_fd + 1, &fdRead, NULL, NULL, NULL)) == -1)
	return (false);      
    }
  else
    {
      time.tv_sec = 0;
      time.tv_usec = wait;
      if ((ret = select(_fd + 1, &fdRead, NULL, NULL, &time)) == -1)
	return (false);
    }
  return (ret != 0);  
}
