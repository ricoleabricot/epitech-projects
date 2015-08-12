//
// Ia_chief.cpp for zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 23 16:52:25 2015 rousse_3
// Last update Thu Jul  2 17:41:25 2015 rousse_3
//

#include	<cstdlib>
#include	<sstream>
#include	<iostream>
#include	"client/Player.hpp"

void		Player::seekFood(void)
{
  std::string		buffer;
  std::stringstream	ss;
  bool			findFood = false;

  if (voir(buffer) != true)
    return;
  buffer = buffer.substr(1, buffer.find(',') - 2);
  ss << buffer;
  while (std::getline(ss, buffer, ' '))
    {
      if (buffer == "nourriture")
	{
	  prend(food);
	  findFood = true;
	}
    }
  if (findFood == false)
    {
      int		choice = rand() % 3;
      switch (choice)
	{
	case 1:
	  avance();
	  break;;
	case 2:
	  droite();
	  avance();
	  break;;
	case 3:
	  gauche();
	  avance();
	  break;;
	case 4:
	  gauche();
	  gauche();
	  avance();
	  break;;
	}
    }
}

void		Player::callHelp(void)
{
  std::stringstream	ss;
  std::string		str;

  ss << "Need Level Up ";
  ss << _level + 1;
  ss >> str;
  broadcast(str);
}

void		Player::joinHim(void)
{
  std::string	msg;
  int		orientation;
  std::stringstream	ss;
  std::string		str;

  ss << "I want Level Up ";
  ss << _level + 1;
  ss >> str;
  broadcast(str);
  getMsg(msg);
  orientation = std::atoi(msg.substr(0, 1).c_str());
  switch(orientation)
    {
    case 1:
    case 2:
    case 8:
      avance();
      break;;
    case 7:
    case 6:
    case 5:
      gauche();
      break;;
    case 4:
    case 3:
      droite();
      break;;
    default:
      break;;
    }
}

bool			Player::needPeople(void)
{
  std::vector<int>	lvl;
  std::string		buffer;
  std::string		square;
  std::stringstream	vue;
  std::stringstream	squareContent;
  int			nbPlayer;

  nbPlayer = 0;
  lvl = getLevel(_level);
  voir(buffer);
  vue << buffer;
  std::getline(vue, square, ',');
  squareContent << square;
  while (std::getline(vue, square, ' '))
    {
      if (square == "player")
	nbPlayer++;
    }
  return (nbPlayer == lvl[0]);
}

bool			Player::canLvlUp(void)
{
  std::vector<int>	lvl;
  int			idx_tab;
  Item			tab[] =
    {
      linemate,
      deraumere,
      sibur,
      mendiane,
      phiras,
      thystame,
      food
    };

  lvl = getLevel(_level);
  if (needPeople())
    return (false);
  idx_tab = 1;
  while (idx_tab < 8)
    {
      if (tab[idx_tab - 1] != lvl[idx_tab])
	return (false);
      idx_tab++;
    }
  return (true);
}

void			Player::seekStone(void)
{
  std::string		buffer;
  std::string		square;
  std::stringstream	vue;
  std::stringstream	squareContent;
  int			choice = rand() % 3;

  voir(buffer);
  vue << buffer;
  std::getline(vue, square, ',');
  squareContent << square;
  while (std::getline(squareContent, square, ' '))
    {
      if (square != "player")
	prend(stringToItem(square));
    }
  switch (choice)
    {
    case 1:
      avance();
      break;;
    case 2:
      droite();
      avance();
      break;;
    case 3:
      gauche();
      avance();
      break;;
    case 4:
      gauche();
      gauche();
      avance();
      break;;
    }
}

void		Player::doSoloDecision(void)
{
  inventaire();
  if (_inventory->getItem(food) < 5)
    seekFood();
  else
    {
      if (canLvlUp())
	incantation();
      else if (needPeople())
	callHelp();
      std::string	msg;

      while (getMsg(msg) == true)
	{
	  if (msg.compare(3, 14, "Need Level Up ") == 0)
	    {
	      if (std::atoi(msg.substr(18, 1).c_str()) == _level)
		{
		  addMsg(msg);
		  joinHim();
		  return;
		}
	    }
	  else if (msg.compare(3, 16, "I want Level Up ") == 0)
	    {
	      if (std::atoi(msg.substr(19, 1).c_str()) == _level)
		{
		  addMsg(msg);
		  callHelp();
		  return;
		}
	    }
	}
      seekStone();
    }
}

void		Player::doRandDecision(void)
{
  int		choice = rand() % 12;
  std::string	buffer;
  int		nb;

  while (_server->readLine(buffer) && _isDead)
    {
      if (buffer == "mort")
	_isDead = true;
      else if (buffer.compare("deplacement: ") == 0)
	_localisation->expulse(buffer.substr(13));
      else if (buffer.compare("message ") == 0)
	_msgs.push_back(buffer.substr(8));
    }
  if (_isDead)
    return;
  switch (choice)
    {
    case 1:
      avance();
      break;;
    case 2:
      droite();
      break;;
    case 3:
      gauche();
      break;;
    case 4:
      inventaire();
      break;;
    case 5:
      prend(food);
      break;;
    case 6:
      pose(food);
      break;;
    case 7:
      voir(buffer);
      break;;
    // case 8:
    //   incantation();
    //   break;;
    case 9:
      expulse();
      break;;
    // case 10:
    //   broadcast("toto");
    //   break;;
    case 11:
      doFork();
      break;;
    case 12:
      connect_nbr(nb);
      break;;
    default:
      break;;
    }
}
