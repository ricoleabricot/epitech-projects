//
// Player.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 24 00:37:12 2015 rousse_3
// Last update Thu Jul  2 17:17:02 2015 rousse_3
//

#include	<cstdlib>
#include	<sstream>
#include	<iostream>
#include	<unistd.h>
#include	<stdexcept>
#include	<sys/wait.h>
#include	"client/Error.hpp"
#include	"client/Player.hpp"

Player::Player(const Option &opt) :
  _opt(opt),
  _inventory(new Inventory),
  _level(1),
  _isDead(false),
  _msgs()
{
  std::string	ip;
  std::string	buffer;
  int		xMax;
  int		yMax;

  opt.getIp(ip);
  _server = new Socket(ip, opt.getPort());
  opt.getTeam(_name);
  _server->wait(-1);
  if (_server->readLine(buffer) != true || buffer != "BIENVENUE")
    throw ConnectionError("Connection Error\n message recu:" + buffer);
  _server->sendData(_name);
  _server->sendData("\n");
  while (_server->readLine(buffer) != true);
  if (buffer == "Team is full")
    throw ConnectionError(buffer);
  while (_server->readLine(buffer) != true);
  xMax = std::atoi(buffer.c_str());
  yMax = std::atoi(buffer.c_str());
  _localisation = new Position(0, 0, xMax, yMax);
}

Player::~Player(void) throw()
{
  end();
}

bool		Player::avance(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("avance\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	{
	  val = true;
	  _localisation->move();
	}
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::droite(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("droite\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	{
	  _localisation->rotate(1);
	  val = true;
	}
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::gauche(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("gauche\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	{
	  _localisation->rotate(-1);
	  val = true;
	}
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::expulse(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("expulse\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	val = true;
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::doFork(void)
{
  int		pid;
  std::string	port;
  std::string	ip;
  std::string	team;
  std::string	name;
  std::stringstream	ss;

  _server->sendData("fork\n");
  ss << _opt.getPort();
  ss >> port;
  _opt.getIp(ip);
  _opt.getTeam(team);
  _opt.getBName(name);
  if ((pid = fork()) == 0)
    {
      execlp(name.c_str(), name.c_str(), "-p", port.c_str(), "-h", ip.c_str(), "-n", team.c_str(), NULL);
      exit(1);
    }
  else
    _pids.push_back(pid);
  return (true);
}

/*
** TODO attendre la fin de l'incantation
*/
bool		Player::incantation(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("incantation\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "incantation en cours")
	val = true;
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::broadcast(const std::string &msg)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("broadcast " + msg + "\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	val = true;
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::prend(Item itm)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  switch (itm)
    {
    case linemate:
      _server->sendData("prend linemate\n");
      break;;
    case deraumere:
      _server->sendData("prend deraumere\n");
      break;;
    case sibur:
      _server->sendData("prend sibur\n");
      break;;
    case mendiane:
      _server->sendData("prend mendiane\n");
      break;;
    case phiras:
      _server->sendData("prend phiras\n");
      break;;
    case thystame:
      _server->sendData("prend thystame\n");
      break;;
    case food:
      _server->sendData("prend nourriture\n");
      break;;
    }
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	{
	  switch (itm)
	    {
	    case linemate:
	      _inventory->addItem(linemate, 1);
	      break;;
	    case deraumere:
	      _inventory->addItem(deraumere, 1);
	      break;;
	    case sibur:
	      _inventory->addItem(sibur, 1);
	      break;;
	    case mendiane:
	      _inventory->addItem(mendiane, 1);
	      break;;
	    case phiras:
	      _inventory->addItem(phiras, 1);
	      break;;
	    case thystame:
	      _inventory->addItem(thystame, 1);
	      break;;
	    case food:	
	      _inventory->addItem(food, 1);
	      break;;
	    }
	  val = true;
	}
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::pose(Item itm)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  switch (itm)
    {
    case linemate:
      _server->sendData("pose linemate\n");
      break;;
    case deraumere:
      _server->sendData("pose deraumere\n");
      break;;
    case sibur:
      _server->sendData("pose sibur\n");
      break;;
    case mendiane:
      _server->sendData("pose mendiane\n");
      break;;
    case phiras:
      _server->sendData("pose phiras\n");
      break;;
    case thystame:
      _server->sendData("pose thystame\n");
      break;;
    case food:
      _server->sendData("pose nourriture\n");
      break;;
    }
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "ok")
	{
	  switch (itm)
	    {
	    case linemate:
	      _inventory->takeItem(linemate, 1);
	      break;;
	    case deraumere:
	      _inventory->takeItem(deraumere, 1);
	      break;;
	    case sibur:
	      _inventory->takeItem(sibur, 1);
	      break;;
	    case mendiane:
	      _inventory->takeItem(mendiane, 1);
	      break;;
	    case phiras:
	      _inventory->takeItem(phiras, 1);
	      break;;
	    case thystame:
	      _inventory->takeItem(thystame, 1);
	      break;;
	    case food:	
	      _inventory->takeItem(food, 1);
	      break;;
	    }
	  val = true;
	}
      else if (buffer == "ko");
      else if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::voir(std::string &str)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  str = "";
  _server->sendData("voir\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	{
	  val = true;
	  str = buffer;
	}
      if (ret == false)
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::inventaire(void)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  _server->sendData("inventaire\n");
  while (_server->readLine(buffer) != true);
  while (ret == false)
    {
      ret = true;
      if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	{
	  val = true;
	  _inventory->initialize(buffer);
	}
      if (ret == false)
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::connect_nbr(int &nb)
{
  std::string	buffer;
  bool		ret = false;
  bool		val = false;

  nb = 0;
  _server->sendData("connect_nbr\n");
  while (_server->readLine(buffer));
  while (ret == false)
    {
      ret = true;
      if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	{
	  ret = false;
	  _localisation->expulse(buffer.substr(13));
	}
      else if (buffer.compare("message ") == 0)
	{
	  ret = false;
	  _msgs.push_back(buffer.substr(8));
	}
      else
	{
	  val = true;
	  nb = std::atoi(buffer.c_str());
	}
      if (ret == false)
	ret = !_server->readLine(buffer);
    }
  return (val);
}

bool		Player::isDead(void) const
{
  return (_isDead);
}

bool		Player::getMsg(std::string &msg)
{
  bool		ret = false;

  if (_msgs.size() > 0)
    {
      msg = _msgs[0];
      _msgs.erase(_msgs.begin());
      ret = true;
    }
  return (ret);
}

void		Player::addMsg(const std::string &msg)
{
  _msgs.push_back(msg);
}

void		Player::end(void) const
{
  std::vector<int>::const_iterator	it = _pids.begin();
  std::vector<int>::const_iterator	end = _pids.end();

  while (it != end)
    {
      waitpid(*it, NULL, 0);
      ++it;
    }
}
