//
// Position.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 14:03:49 2015 rousse_3
// Last update Sat Jun 27 00:48:23 2015 rousse_3
//

#include		<cstdlib>
#include		"client/Position.hpp"

Position::Position(int x, int y, int xMax, int yMax) : _x(x), _y(y), _xMax(xMax), _yMax(yMax), _orientation(Position::UP) {}

Position::~Position(void) throw() {}

bool			Position::operator<(const Position &pos) const
{
  if (pos._x < _x)
    return (false);
  else if (pos._x > _x)
    return (true);
  else if (pos._y < _y)
    return (false);
  else
    return (true);
}

int			Position::getX(void) const
{
  return (_x);
}

int			Position::getY(void) const
{
  return (_y);
}

Position::orientation	Position::getOrientation(void) const
{
  return (_orientation);
}

void			Position::rotate(int rotate)
{
  if (rotate > 0)
    {
      switch (_orientation)
	{
	case Position::UP:
	  _orientation = Position::RIGHT;
	  break;;
	case Position::RIGHT:
	  _orientation = Position::DOWN;
	  break;;
	case Position::DOWN:
	  _orientation = Position::LEFT;
	  break;;
	case Position::LEFT:
	  _orientation = Position::UP;
	  break;;
	}
    }
  else
    {
      switch (_orientation)
	{
	case Position::UP:
	  _orientation = Position::LEFT;
	  break;;
	case Position::RIGHT:
	  _orientation = Position::UP;
	  break;;
	case Position::DOWN:
	  _orientation = Position::RIGHT;
	  break;;
	case Position::LEFT:
	  _orientation = Position::DOWN;
	  break;;
	}
    }
}

void		Position::move(void)
{
  switch (_orientation)
    {
    case Position::UP:
      _y = (_y + 1) % _yMax;
    case Position::RIGHT:
      _x = (_x + 1) % _xMax;
    case Position::DOWN:
      _y -= 1;
      if (_y < 0)
	_y+= _yMax;
      break;;
    case Position::LEFT:
      _x -= 1;
      if (_x < 0)
	_x+= _xMax;
      break;;
    }
}

void		Position::expulse(const std::string &square)
{
  int		squareNum = std::atoi(square.c_str()) / 2;
  Position::orientation	tab[] = {Position::UP, Position::LEFT, Position::DOWN, Position::RIGHT};
  int		idx = 0;
  Position::orientation	tmp;

  while (tab[idx] != _orientation)
    idx++;
  idx = (idx + squareNum) % 4;
  tmp = _orientation;
  _orientation = tab[idx];
  move();
  _orientation = tmp;
}
