//
// Map.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 18 22:10:11 2015 rousse_3
// Last update Thu Jun 18 22:44:01 2015 rousse_3
//

#include		"client/Map.hpp"

Map::Map(int sizeX, int sizeY) : _sizeX(sizeX), _sizeY(sizeY), _map() {}

Map::~Map(void) throw() {}

int			Map::getSizeX(void) const
{
  return (_sizeX);
}

int			Map::getSizeY(void) const
{
  return (_sizeY);
}

Square			&Map::getSquare(const Position &pos)
{
  std::map<Position, Square>::iterator	square = _map.find(pos);

  if (square == _map.end())
    {
      addSquare(pos);
      square = _map.find(pos);
    }
  return ((*square).second);
}

bool			Map::addSquare(const Position &pos)
{
  std::map<Position, Square>::iterator	square = _map.find(pos);
  bool			exist = true;

  if (square != _map.end())
    {
      _map.insert(std::pair<Position, Square>(pos, Square(pos)));
      exist = true;
    }
  return (exist);
}

void			Map::update(void)
{
  std::map<Position, Square>::iterator	it = _map.begin();
  std::map<Position, Square>::iterator	end = _map.end();

  while (it != end)
    {
      (*it).second.update();
      ++it;
    }
}
