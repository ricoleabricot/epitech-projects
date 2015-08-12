//
// Player.cpp for zappy in /home/ribeir_b/rendu/PSU_2014_zappy
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jul  1 12:58:11 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 20:06:27 2015 Nicolas Ribeiro Teixeira
//

#include	<string>
#include	"graphic/Player.hh"

Player::Player(int id, int x, int y, int lvl, int orientation, std::string teamname, int state) : m_id(id), m_x(x), m_y(y), m_lvl(lvl), m_orientation(orientation), m_teamname(teamname), m_state(state)
{
  m_inventory[0] = 10;
  m_inventory[1] = 10;
  m_inventory[2] = 10;
  m_inventory[3] = 10;
  m_inventory[4] = 10;
  m_inventory[5] = 10;
  m_inventory[6] = 10;
}

Player::~Player()
{
}

void		Player::resetId(void)
{
  m_id = -1;
}

void		Player::setX(int x)
{
  m_x = x;
}

void		Player::setY(int y)
{
  m_y = y;
}

void		Player::setLvl(int lvl)
{
  m_lvl = lvl;
}

void		Player::setOrientation(int orientation)
{
  m_orientation = orientation;
}

void		Player::setInventory(int tab[7])
{
  m_inventory[0] = tab[0];
  m_inventory[1] = tab[1];
  m_inventory[2] = tab[2];
  m_inventory[3] = tab[3];
  m_inventory[4] = tab[4];
  m_inventory[5] = tab[5];
  m_inventory[6] = tab[6];
}

void		Player::setState(int state)
{
  m_state = state;
}

void		Player::setTimer(int time)
{
  m_timer = time;
}

void		Player::decrementTimer(int decr)
{
  m_timer -= decr;
}

int		Player::getX(void) const
{
  return (m_x);
}

int		Player::getY(void) const
{
  return (m_y);
}

int		Player::getLvl(void) const
{
  return (m_lvl);
}

int		Player::getOrientation(void) const
{
  return (m_orientation);
}

int		Player::getInventory(int index) const
{
  return (m_inventory[index]);
}

int		Player::getId(void) const
{
  return (m_id);
}

std::string const	&Player::getTeam(void) const
{
  return (m_teamname);
}

int			Player::getState(void) const
{
  return (m_state);
}

int			Player::getTimer(void) const
{
  return (m_timer);
}
