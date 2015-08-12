//
// Error.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 19:52:54 2015 rousse_3
// Last update Wed Jun 17 20:14:24 2015 rousse_3
//

#include		"client/Error.hpp"

ClientError::ClientError(void) {}
ClientError::~ClientError(void) throw() {}

ConnectionError::ConnectionError(const std::string &error) :
  std::runtime_error(error),
  _error(error.c_str())
{}

ConnectionError::~ConnectionError(void) throw() {}

const char		*ConnectionError::what(void) const throw()
{
  return (_error);
}
