//
// Option.cpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 20:34:50 2015 rousse_3
// Last update Sat Jun 27 19:02:28 2015 rousse_3
//

#include	<cstdlib>
#include	<sstream>
#include	<iostream>
#include	"client/Option.hpp"

void		Option::setTeam(int idx, int argc, const char **argv)
{
  if (argc >idx + 1) 
    {
      if (_team == "")
	_team = argv[idx + 1];
      else
	{
	  std::cerr << "You can only enter one port" << std::endl;
	  _isValid = false;
	}
    }
  else
    {
      std::cerr << "You must enter a parameter after a flag -p" << std::endl;
      _isValid = false;
    }
}

void		Option::setIp(int idx, int argc, const char **argv)
{
  if (argc >idx + 1) 
    {
      if (_ip == "")
	_ip = argv[idx + 1];
      else
	{
	  std::cerr << "You can only enter one port" << std::endl;
	  _isValid = false;
	}
    }
  else
    {
      std::cerr << "You must enter a parameter after a flag -p" << std::endl;
      _isValid = false;
    }
}

void		Option::setPort(int idx, int argc, const char **argv)
{
  if (argc >idx + 1) 
    {
      if (_port == -1)
	_port = std::atoi(argv[idx + 1]);
      else
	{
	  std::cerr << "You can only enter one port" << std::endl;
	  _isValid = false;
	}
    }
  else
    {
      std::cerr << "You must enter a parameter after a flag -p" << std::endl;
      _isValid = false;
    }
}

Option::Option(int argc, const char **argv) :
  _bname(argv[0]),
  _isValid(true),
  _team(""),
  _ip(""),
  _port(-1)
{
  int		idx = 1;

  while (idx < argc && _isValid == true)
    {
      std::string	arg(argv[idx]);

      if (arg == "-p")
	{
	  setPort(idx, argc, argv);
	  idx++;
	}
      else if (arg == "-n")
	{
	  setTeam(idx, argc, argv);
	  idx++;
	}
      else if (arg == "-h")
	{
	  setIp(idx, argc, argv);
	  idx++;
	}
      else
	{
	  std::cerr << "Unknown option " << arg << std::endl;
	  _isValid = false;
	}
      idx++;
    }
  if (_team == "")
    {
      std::cerr << "You must enter a team name" << std::endl;
      _isValid = false;
    }
  if (_port == -1)
    {
      std::cerr << "You must enter a port" << std::endl;
      _isValid = false;
    }
  if (_isValid == false)
    std::cerr << "Usage : ./client -p port -n team [ -h ip ]" << std::endl;
  if (_ip == "")
    _ip = "127.0.0.1";
}

Option::Option(const Option &opt) :
  _bname(opt._bname),
  _isValid(opt._isValid),
  _team(opt._team),
  _ip(opt._ip),
  _port(opt._port)
{}

Option::~Option(void) throw() {}

void		Option::getBName(std::string &bname) const
{
  bname = _bname;
}

bool		Option::isValid(void) const
{
  return (_isValid);
}

void		Option::getTeam(std::string &team) const
{
  team = _team;
}

void		Option::getIp(std::string &ip) const
{
  ip = _ip;
}

int		Option::getPort(void) const
{
  return (_port);
}
