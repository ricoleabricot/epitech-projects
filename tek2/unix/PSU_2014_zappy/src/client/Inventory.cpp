//
// Inventory.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 17:39:49 2015 rousse_3
// Last update Thu Jul  2 17:47:50 2015 rousse_3
//

#include				<cstdlib>
#include				<sstream>
#include				"client/Inventory.hpp"

Inventory::Inventory(void) : _items() {}

Inventory::~Inventory(void) throw() {}

void					Inventory::initialize(const std::string &str)
{
  std::stringstream			ss;
  std::string				buffer;
  size_t				i;

  _items.erase(_items.begin(), _items.end());
  buffer = str.substr(0, str.length() - 1).substr(1);
  ss << buffer;
  while (std::getline(ss, buffer, ','))
    {
      i = 0;
      while (i < _items.size() && stringToItem(buffer) != _items[i].first)
	i++;
      if (i == _items.size())
	_items.push_back(std::pair<Item, int>(stringToItem(buffer), 1));  
      else
	_items[i].second += 1;
    }
}

int					Inventory::getItem(Item item) const
{
  Inventory::storage::const_iterator	it = _items.begin();
  Inventory::storage::const_iterator	end = _items.end();
  int					nb = 0;

  while (it != end)
    {
      if ((*it).first == item)
	nb = (*it).second;
      ++it;
    }
  return (nb);
}

void					Inventory::addItem(Item item, int nb)
{
  Inventory::storage::iterator		it = _items.begin();
  Inventory::storage::iterator		end = _items.end();
  bool					exist = false;

  while (it != end)
    {
      if ((*it).first == item)
	{
	  (*it).second += nb;
	  exist = true;
	}
      ++it;
    }
  if (exist == false)
    _items.push_back(std::pair<Item, int>(item, nb));
}

bool					Inventory::takeItem(Item item, int nb)
{
  Inventory::storage::iterator		it = _items.begin();
  Inventory::storage::iterator		end = _items.end();
  bool					haveTake = false;

  while (it != end)
    {
      if ((*it).first == item)
	{
	  if ((*it).second >= nb)
	    {
	      (*it).second -= nb;
	      haveTake = true;
	    }
	}
      ++it;
    }
  return (haveTake);
}
