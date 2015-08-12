//
// Square.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 18 17:30:04 2015 rousse_3
// Last update Thu Jun 18 17:47:26 2015 rousse_3
//

#include			"client/Square.hpp"

Square::Square(const Position &pos) :
  _pos(pos),
  _content(),
  _habitant(),
  _lastUpdate(0)
{}

Square::~Square(void) throw() {}

const std::vector<Item>		&Square::getItems(void) const
{
  return (_content);
}

const std::vector<Player*>	&Square::getPlayers(void) const
{
  return (_habitant);
}

int				Square::getLastUpdate(void) const
{
  return (_lastUpdate);
}

void				Square::addItems(Item item)
{
  _content.push_back(item);
}

void				Square::addPlayer(Player *player)
{
  _habitant.push_back(player);
}

void				Square::delItem(Item item)
{
  std::vector<Item>::iterator	it = _content.begin();
  std::vector<Item>::iterator	end = _content.end();
  bool				hasBeenDeleted = false;

  while (it != end && hasBeenDeleted == false)
    {
      if (*it == item)
	{
	  _content.erase(it);
	  hasBeenDeleted = true;
	}
      ++it;
    }
}

void				Square::delPlayer(Player *player)
{
  std::vector<Player*>::iterator	it = _habitant.begin();
  std::vector<Player*>::iterator	end = _habitant.end();
  bool				hasBeenDeleted = false;

  while (it != end && hasBeenDeleted == false)
    {
      if (*it == player)
	{
	  _habitant.erase(it);
	  hasBeenDeleted = true;
	}
      ++it;
    }
}

void				Square::update(void)
{
  _lastUpdate++;
}
